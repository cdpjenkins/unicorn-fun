
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include "FreeRTOS.h"
#include <queue.h>
#include <message_buffer.h>

#include "CosmicUnicornDisplayAgent.hpp"

#include "Agent.hpp"

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "conway/ConwayGrid.hpp"
#include "WithMutexLock.hpp"
#include "images/Cat32x32.hpp"
#include "images/CatFace32x32.hpp"
#include "images/PigNose32x32.hpp"
#include "images/PigFace32x32.hpp"
#include "images/Pig32x32.hpp"
#include "images/HeartCat32x32.hpp"
#include "images/DogFace32x32.hpp"
#include "images/Dog32x32.hpp"

using namespace pimoroni;

CosmicUnicornDisplayAgent::CosmicUnicornDisplayAgent() :
        Agent("CosmicUnicornDisplayAgent",
              configMINIMAL_STACK_SIZE * 8,
              tskIDLE_PRIORITY + 2UL),
        brightness(64),
        scroll_text_app()
{
    command_queue = xQueueCreate(16, sizeof(CosmicUnicornDisplayCommand));
    cosmic_unicorn.init();

    command_message_buffer = xMessageBufferCreate(1024);
    message_buffer_mutex = xSemaphoreCreateMutex();
    if (message_buffer_mutex == nullptr) {
        throw std::runtime_error("Failed to create message_buffer_mutex");
    }

}

static void task_stats() {
    TaskStatus_t *pxTaskStatusArray;
    volatile UBaseType_t uxArraySize, x;
    unsigned long ulTotalRunTime;

    uxArraySize = uxTaskGetNumberOfTasks();
    printf("Number of tasks %lu\n", uxArraySize);

    pxTaskStatusArray = (TaskStatus_t *)pvPortMalloc( uxArraySize * sizeof(TaskStatus_t) );

    if(pxTaskStatusArray != nullptr) {
        uxArraySize = uxTaskGetSystemState(pxTaskStatusArray,
                                           uxArraySize,
                                           &ulTotalRunTime);

        for( x = 0; x < uxArraySize; x++ )
        {
            printf("Task: %lu \t cPri:%lu \t bPri:%lu \t hw:%4lu \t%s\n",
                   pxTaskStatusArray[ x ].xTaskNumber ,
                   pxTaskStatusArray[ x ].uxCurrentPriority ,
                   pxTaskStatusArray[ x ].uxBasePriority ,
                   pxTaskStatusArray[ x ].usStackHighWaterMark ,
                   pxTaskStatusArray[ x ].pcTaskName
            );
        }

        vPortFree(pxTaskStatusArray);
    } else {
        printf("Failed to allocate space for stats\n");
        throw std::runtime_error("Failed to allocate space for stats");
    }

    HeapStats_t heapStats;
    vPortGetHeapStats(&heapStats);
    printf("HEAP avl: %d, blocks %d, alloc: %d, free: %d\n",
           heapStats.xAvailableHeapSpaceInBytes,
           heapStats.xNumberOfFreeBlocks,
           heapStats.xNumberOfSuccessfulAllocations,
           heapStats.xNumberOfSuccessfulFrees
    );
}

[[noreturn]]
void CosmicUnicornDisplayAgent::task_main() {
    tick_timer = xTimerCreate("tick_timer",
                              100,
                              true,
                              (void *)this,
                              timer_callback);
    xTimerStart(tick_timer, 1000);

    ConwayGrid grid;
    grid.invert_cell(3, 1);
    grid.invert_cell(3, 2);
    grid.invert_cell(3, 3);
    grid.invert_cell(2, 3);
    grid.invert_cell(1, 2);
    grid.run();

    char receive_buffer[1024];

    while (true) {
        size_t receive_length = xMessageBufferReceive(
                command_message_buffer,
                receive_buffer,
                1024,
                1000
        );
        if (receive_length > 0) {
            std::string command{receive_buffer};

            if (command == "activate scroll_text") {
                active_app = &scroll_text_app;
            } else if (command == "activate picture") {
                // TODO
            } else if (command == "deactivate") {
                active_app = nullptr;
            } else if (command == "cat") {
                display_image(Cat32x32::image);
            } else if (command == "cat_face") {
                display_image(CatFace32x32::image);
            } else if (command == "dog") {
                display_image(Dog32x32::image);
            } else if (command == "dog_face") {
                display_image(DogFace32x32::image);
            } else if (command == "heart_cat") {
                display_image(HeartCat32x32::image);
            } else if (command == "pig") {
                display_image(Pig32x32::image);
            } else if (command == "pig_face") {
                display_image(PigFace32x32::image);
            } else if (command == "pig_nose") {
                display_image(PigNose32x32::image);
            } else if (command == "clear") {
                clear_display();
            } else if (command == "stats") {
                task_stats();
            } else if (command.rfind("text ", 0) == 0) {
                std::string text = command.substr(5);
                display_text(text.c_str());
            } else if (command.rfind("set_text ", 0) == 0) {
                std::string text = command.substr(9);
                scroll_text_app.set_text(text.c_str());
            } else if (command.rfind("tick", 0) == 0) {
                tick();
            } else if (command.rfind("brightness ", 0) == 0) {
                std::string text = command.substr(11);
                printf("%s\n", text.c_str());

                try {
                    int value = std::stoi(text);

                    brightness = value;
                } catch (std::invalid_argument &e) {
                    printf("%s\n", e.what());
                }
            } else if (command == "conway display") {
                conway_step(grid);
            } else {
                printf("Command not recognised: %s\n", command.c_str());
            }
        }
    }
}

void CosmicUnicornDisplayAgent::tick() {
    if (active_app != nullptr) {
        active_app->update(graphics);
        active_app->draw(cosmic_unicorn, graphics);
    }
}

void CosmicUnicornDisplayAgent::conway_step(ConwayGrid &grid) {
    grid.step();

    for (int y = 0; y < grid.height; y++) {
        for (int x = 0; x < grid.width; x++) {
            if (grid.cell_alive_at(x, y)) {
                printf("%d,%d\n", x, y);

                plot_pixel(Point(x, y), 0xFF, 0xFF, 0xFF);
            } else {
                plot_pixel(Point(x, y), 0x00, 0x00, 0x00);
            }
        }
    }
    cosmic_unicorn.update(&graphics);
}

void CosmicUnicornDisplayAgent::display_text(const char *text_cstr) {
    scroll_text_app.display_text(text_cstr, cosmic_unicorn, graphics);
}

void CosmicUnicornDisplayAgent::display_image(const uint8_t image[3072]) {
    const uint8_t *p = image;
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < HEIGHT; x++) {
            uint8_t r = *p++;
            uint8_t g = *p++;
            uint8_t b = *p++;

            plot_pixel(Point(x, y), r, g, b);
        }
    }

    cosmic_unicorn.update(&graphics);
}

void CosmicUnicornDisplayAgent::plot_pixel(const Point &point, uint8_t red, uint8_t green, uint8_t blue) {
    int r = ((int)red   * brightness) / 256;
    int g = ((int)green * brightness) / 256;
    int b = ((int)blue  * brightness) / 256;

    graphics.set_pen(r, g, b);
    graphics.pixel(point);
}

void CosmicUnicornDisplayAgent::send(CosmicUnicornDisplayCommand *pCommand) {
    BaseType_t rc = xQueueSendToBack(command_queue, pCommand, 0);
    if (rc != pdTRUE) {
        printf("Failed to send message: %ld\n", rc);
    }
}

void CosmicUnicornDisplayAgent::send_command(char *command_string) {
    WithMutexLock mutex_lock(message_buffer_mutex);

    if(mutex_lock.lock()) {
        size_t command_length = strlen(command_string) + 1;

        size_t res = xMessageBufferSend(
                command_message_buffer,
                command_string,
                command_length,
                0);

        if (res != command_length){
            printf("ERROR: failed to write whole message to buffer: %s\n", res);
        }
    }
    else
    {
        printf("Failed to get mutex so looks like we're not going to execute command: %s\n", command_string);
    }
}

void CosmicUnicornDisplayAgent::clear_display() {
    graphics.set_pen(0, 0, 0);
    graphics.clear();

    cosmic_unicorn.update(&graphics);
}

void CosmicUnicornDisplayAgent::timer_callback(TimerHandle_t timer) {
    void *timer_id = pvTimerGetTimerID(timer);

    CosmicUnicornDisplayAgent *display_agent = static_cast<CosmicUnicornDisplayAgent *>(timer_id);

    display_agent->send_command((char*)"tick");
}

