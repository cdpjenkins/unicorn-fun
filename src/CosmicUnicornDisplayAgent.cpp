
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include "FreeRTOS.h"
#include <queue.h>

#include "CosmicUnicornDisplayAgent.hpp"

#include "Agent.hpp"


#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"
#include "images/CatFace32x32.hpp"
#include "images/Dog32x32.hpp"
#include "images/HeartCat32x32.hpp"
#include "images/Cat32x32.hpp"
#include "images/DogFace32x32.hpp"

using namespace pimoroni;

CosmicUnicornDisplayAgent::CosmicUnicornDisplayAgent() :
        Agent("leds_task",
              configMINIMAL_STACK_SIZE * 2,
              tskIDLE_PRIORITY + 1UL),
        brightness(64)
{
    command_queue = xQueueCreate(16, sizeof(CosmicUnicornDisplayCommand));
    cosmic_unicorn.init();
}

[[noreturn]]
void CosmicUnicornDisplayAgent::task_main() {
    printf("Yo!\n");

    while (true) {
        CosmicUnicornDisplayCommand command;
        BaseType_t rc = xQueueReceive(command_queue, (void *)&command, 1000);
        if (rc == pdTRUE) {
            switch (command.command_type) {
                case DISPLAY_IMAGE:
                    display_image(command.body.display_image_command.image);
                    break;
                case CLEAR:
                    clear_display();
                    break;
                case TEXT:
                    display_text(command.body.text_command.text);
                    break;
                case BRIGHTNESS: {
                    brightness = command.body.brightness_command.brightness;
                    const std::string &cstr = std::to_string(brightness);
                    break;
                }
                default:
                    printf("Unrecognised command: %d\n", command.command_type);
                    break;
            }
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

void CosmicUnicornDisplayAgent::display_text(char *text_cstr) {
    constexpr int TEXT_HEIGHT = 7;

    std::istringstream iss(text_cstr);
    std::string line;

    graphics.set_pen(0, 0, 0);
    graphics.clear();

    int y = 0;
    while (std::getline(iss, line, '_')) {
        graphics.set_pen(32, 32, 32);
        graphics.text(line, Point(0, y), -1, 0.55);

        y += TEXT_HEIGHT;
    }

    cosmic_unicorn.update(&graphics);
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

void CosmicUnicornDisplayAgent::clear_display() {
    graphics.set_pen(0, 0, 0);
    graphics.clear();

    cosmic_unicorn.update(&graphics);
}
