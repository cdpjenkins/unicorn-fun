
#include <cstdio>

#include "FreeRTOS.h"
#include <queue.h>

#include "CosmicUnicornDisplayAgent.hpp"

#include "Agent.hpp"


#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"
#include "CatFace32x32.hpp"
#include "Dog32x32.hpp"
#include "HeartCat32x32.hpp"
#include "Cat32x32.hpp"
#include "DogFace32x32.hpp"

using namespace pimoroni;

CosmicUnicornDisplayAgent::CosmicUnicornDisplayAgent(pimoroni::CosmicUnicorn &unicorn, PicoGraphics_PenRGB888 &rgb888) :
        Agent("leds_task",
              configMINIMAL_STACK_SIZE,
              tskIDLE_PRIORITY + 1UL),
        cosmic_unicorn(unicorn),
        graphics(rgb888)
{
    command_queue = xQueueCreate(16, sizeof(CosmicUnicornDisplayCommand));
}

[[noreturn]]
void CosmicUnicornDisplayAgent::task_main() {
    printf("Yo!\n");

    while (true) {
        CosmicUnicornDisplayCommand command;
        BaseType_t rc = xQueueReceive(command_queue, (void *)&command, 1000);
        if (rc == pdTRUE) {
            display_image(command.pixels);
        }
    }

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

        vTaskDelay(DELAY);
    }
}

void CosmicUnicornDisplayAgent::display_image(const uint8_t image[3072]) {
    const uint8_t *p = image;
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < HEIGHT; x++) {
            uint8_t r = *p++;
            uint8_t g = *p++;
            uint8_t b = *p++;

            graphics.set_pen(r / 8, g / 8, b / 8);
            graphics.pixel(Point(x, y));
        }
    }

    cosmic_unicorn.update(&graphics);
}

void CosmicUnicornDisplayAgent::send(CosmicUnicornDisplayCommand *pCommand) {
    BaseType_t rc = xQueueSendToBack(command_queue, pCommand, 0);
    if (rc != pdTRUE) {
        printf("Failed to send message: %ld\n", rc);
    }
}
