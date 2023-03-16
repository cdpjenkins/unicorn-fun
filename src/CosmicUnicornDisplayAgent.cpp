
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include "FreeRTOS.h"
#include <queue.h>

#include "CosmicUnicornDisplayAgent.hpp"

#include "Agent.hpp"

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "conway/ConwayGrid.hpp"

using namespace pimoroni;

CosmicUnicornDisplayAgent::CosmicUnicornDisplayAgent() :
        Agent("leds_task",
              configMINIMAL_STACK_SIZE * 4,
              tskIDLE_PRIORITY + 1UL),
        brightness(64)
{
    command_queue = xQueueCreate(16, sizeof(CosmicUnicornDisplayCommand));
    cosmic_unicorn.init();
}

[[noreturn]]
void CosmicUnicornDisplayAgent::task_main() {
    printf("Yo!\n");

    ConwayGrid grid;
    grid.invert_cell(3, 1);
    grid.invert_cell(3, 2);
    grid.invert_cell(3, 3);
    grid.invert_cell(2, 3);
    grid.invert_cell(1, 2);
    grid.run();

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
                case DISPLAY_CONWAY_GRID: {
                    grid.step();

                    printf("Display grid me do\n");
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
                    printf("Displayed that grid!\n");

                    break;
                }
                default:
                    printf("Unrecognised command: %d\n", command.command_type);
                    break;
            }
        }
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
