#include <iostream>
#include "ConwayApp.hpp"

void ConwayApp::update(pimoroni::PicoGraphics_PenRGB888 &graphics) {
    grid.step();
}

// Massive duplication! Should pull this into somewhere common.
static void plot_pixel(pimoroni::PicoGraphics_PenRGB888 &graphics,
                       const pimoroni::Point &point,
                       uint8_t red,
                       uint8_t green,
                       uint8_t blue) {
    uint8_t brightness = 0x10;

    int r = ((int)red   * brightness) / 256;
    int g = ((int)green * brightness) / 256;
    int b = ((int)blue  * brightness) / 256;

    graphics.set_pen(r, g, b);
    graphics.pixel(point);
}


void ConwayApp::draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const {
    for (int y = 0; y < grid.height; y++) {
        for (int x = 0; x < grid.width; x++) {
            if (grid.cell_alive_at(x, y)) {
                plot_pixel(graphics, pimoroni::Point(x, y), 0xFF, 0xFF, 0xFF);
            } else {
                plot_pixel(graphics, pimoroni::Point(x, y), 0x00, 0x00, 0x00);
            }
        }
    }
    cosmic_unicorn.update(&graphics);
}

ConwayApp::ConwayApp() {
    add_hardcoded_glider();
    grid.run();
}

void ConwayApp::add_hardcoded_glider() {
    grid.invert_cell(3, 1);
    grid.invert_cell(3, 2);
    grid.invert_cell(3, 3);
    grid.invert_cell(2, 3);
    grid.invert_cell(1, 2);
}
