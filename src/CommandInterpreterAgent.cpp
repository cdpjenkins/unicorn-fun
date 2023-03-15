#include <FreeRTOS.h>
#include <message_buffer.h>

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include "CommandInterpreterAgent.hpp"
#include "images/oi.h"
#include "images/babi.h"
#include "images/clear.h"
#include "images/Cat32x32.hpp"
#include "images/CatFace32x32.hpp"
#include "images/Dog32x32.hpp"
#include "images/DogFace32x32.hpp"
#include "images/HeartCat32x32.hpp"

CommandInterpreterAgent::CommandInterpreterAgent(CosmicUnicornDisplayAgent &agent) :
        Agent("command_interpreter_task",
              configMINIMAL_STACK_SIZE * 4,
              tskIDLE_PRIORITY + 2),
        cosmic_unicorn_agent(agent)
{
    message_buffer = xMessageBufferCreate(1024);
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


void CommandInterpreterAgent::task_main() {

    char receive_buffer[1024];

    while (true) {
        size_t receive_length = xMessageBufferReceive(
                message_buffer,
                receive_buffer,
                1024,
                1000
        );
        if (receive_length > 0) {
            std::string command{receive_buffer};

            if (command == "cat") {
                send_image_command(Cat32x32::image);
            } else if (command == "cat_face") {
                send_image_command(CatFace32x32::image);
            } else if (command ==  "dog") {
                send_image_command(Dog32x32::image);
            } else if (command ==  "dog_face") {
                send_image_command(DogFace32x32::image);
            } else if (command == "heart_cat") {
                send_image_command(HeartCat32x32::image);
            } else if (command == "clear") {
                send_clear_command();
            } else if (command == "stats") {
                task_stats();
            } else if (command.rfind("text ", 0) == 0) {
                std::string text = command.substr(5);
                send_text_command(text);
            } else if (command.rfind("brightness ", 0) == 0) {
                std::string text = command.substr(11);
                printf("%s\n", text.c_str());

                try {
                    int value = std::stoi(text);

                    send_brightness_command((uint8_t)value);
                } catch (std::invalid_argument &e) {
                    printf("%s\n", e.what());
                }
            } else if (command == "conway display") {
                send_command_conway_display();
            } else {
                printf("Command not recognised: %s\n", command.c_str());
            }
        } else {
            // I guess 0 means nothing was sent
        }
    }
}

void CommandInterpreterAgent::send_command(char *command_string) {
    size_t command_length = strlen(command_string) + 1;

    size_t  res = xMessageBufferSend(
            message_buffer,
            command_string,
            command_length,
            0);

    if (res != command_length){
        printf("ERROR: failed to write whole message to buffer\n");
    }
}

void CommandInterpreterAgent::send_image_command(const uint8_t *image) {
    CosmicUnicornDisplayCommand command{DISPLAY_IMAGE};
    command.body.display_image_command.init(image);

    cosmic_unicorn_agent.send(&command);
}

void CommandInterpreterAgent::send_clear_command() {
    CosmicUnicornDisplayCommand command{CLEAR};
    command.body.clear_command.init(0);

    cosmic_unicorn_agent.send(&command);
}

void CommandInterpreterAgent::send_text_command(std::string text) {
    CosmicUnicornDisplayCommand command{TEXT};
    command.body.text_command.init(text.c_str());

    cosmic_unicorn_agent.send(&command);
}

void CommandInterpreterAgent::send_brightness_command(uint8_t brightness) {
    CosmicUnicornDisplayCommand command{BRIGHTNESS};
    command.body.brightness_command.init(brightness);

    cosmic_unicorn_agent.send(&command);
}

void CommandInterpreterAgent::send_command_conway_display() {
    CosmicUnicornDisplayCommand command{DISPLAY_CONWAY_GRID};

    cosmic_unicorn_agent.send(&command);
}
