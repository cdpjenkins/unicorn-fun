
#include <cstdio>

#include "FreeRTOS.h"
#include <queue.h>

#include "LEDsAgent.hpp"

#include "Agent.hpp"


#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"
using namespace pimoroni;



LEDsAgent::LEDsAgent(pimoroni::CosmicUnicorn &unicorn, PicoGraphics_PenRGB888 &rgb888) :
        Agent("leds_task",
              configMINIMAL_STACK_SIZE,
              tskIDLE_PRIORITY + 1UL),
        cosmic_unicorn(unicorn),
        graphics(rgb888)
{
    command_queue = xQueueCreate(16, sizeof(LEDsCommand));
}

[[noreturn]]
void LEDsAgent::task_main() {

    printf("Yo!\n");

    int i = 0;
    while (true) {
        printf("Looping...");

        graphics.set_pen(0, 0, 0);
        graphics.clear();
        graphics.set_pen(128, 128, 128);
        graphics.text("Hello", Point(0, 0), -1, 0.55);
        graphics.text("World", Point(0, 8), -1, 0.55);
        graphics.text(std::to_string(i++), Point(0, 16), -1, 0.55);

        printf("Drawn!\n");

        cosmic_unicorn.update(&graphics);


        printf("Drew!\n");


        vTaskDelay(1000);

    }

//    std::string message = "Oi baby!";
//
//
//    PicoGraphics_PenRGB888 graphics(32, 32, nullptr);
//    CosmicUnicorn cosmic_unicorn;
//
//
//    printf("About to init...!\n");
//
//    cosmic_unicorn.init();
//
//    printf("Did init!\n");
//
//    graphics.set_pen(128, 128, 128);
//    graphics.text("Oi baby!", Point(0, 14), -1, 0.55);
//
//
//    printf("Drawn!\n");
//
//    cosmic_unicorn.update(&graphics);
//
//
//    printf("Drew!\n");

    while (true) {
        printf("Delay...\n");
        vTaskDelay(1000);
    }

//    pico_unicorn.init();
//
//    while (true) {
//        LEDsCommand command;
//        BaseType_t rc = xQueueReceive(command_queue, (void *)&command, 1000);
//        if (rc == pdTRUE) {
//            int i = 0;
//            for (int y = 0; y < HEIGHT; y++) {
//                for (int x = 0; x < WIDTH; x++) {
//                    unsigned char r = command.pixels[i++];
//                    unsigned char g = command.pixels[i++];
//                    unsigned char b = command.pixels[i++];
//                    pico_unicorn.set_pixel(x, y, r, g, b);
//                }
//            }
//        }
//    }
}

void LEDsAgent::send(LEDsCommand *pCommand) {
    BaseType_t rc = xQueueSendToBack(command_queue, pCommand, 0);
    if (rc != pdTRUE) {
        printf("Failed to send message: %ld\n", rc);
    }
}

