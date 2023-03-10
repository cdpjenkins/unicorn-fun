
#include <cstdio>

#include "FreeRTOS.h"
#include <queue.h>

#include "LEDsAgent.hpp"

#include "Agent.hpp"


#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"
#include "CatFace32x32.hpp"
#include "Dog32x32.hpp"
#include "HeartCat32x32.hpp"
#include "Cat32x32.hpp"
#include "DogFace32x32.hpp"

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

    constexpr TickType_t DELAY = 10000;

    int i = 0;
    while (true) {

        graphics.set_pen(0, 0, 0);
        graphics.clear();

        display_image(CatFace32x32::image);
        vTaskDelay(DELAY);

        display_image(Cat32x32::image);
        vTaskDelay(DELAY);

        display_image(Dog32x32::image);
        vTaskDelay(DELAY);

        display_image(DogFace32x32::image);
        vTaskDelay(DELAY);

        display_image(HeartCat32x32::image);
        vTaskDelay(DELAY);

        graphics.set_pen(0, 0, 0);
        graphics.clear();

        graphics.set_pen(32, 32, 32);
        graphics.text("Oi", Point(0, 0), -1, 0.55);
        graphics.text("baby", Point(0, 8), -1, 0.55);
        graphics.text(std::to_string(i++), Point(0, 16), -1, 0.55);

        cosmic_unicorn.update(&graphics);

        printf("Drew!\n");

        vTaskDelay(DELAY);
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

void LEDsAgent::display_image(const uint8_t image[3072]) {
    const uint8_t *p = image;
    for (int y = 0; y < 32; y++) {
        for (int x = 0; x < 32; x++) {
            uint8_t r = *p++;
            uint8_t g = *p++;
            uint8_t b = *p++;

            graphics.set_pen(r / 8, g / 8, b / 8);
            graphics.pixel(Point(x, y));
        }
    }

    cosmic_unicorn.update(&graphics);
}

void LEDsAgent::send(LEDsCommand *pCommand) {
    BaseType_t rc = xQueueSendToBack(command_queue, pCommand, 0);
    if (rc != pdTRUE) {
        printf("Failed to send message: %ld\n", rc);
    }
}

