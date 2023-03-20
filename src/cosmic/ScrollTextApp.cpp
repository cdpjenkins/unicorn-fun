#include <iostream>
#include <sstream>
#include <string>

#include "ScrollTextApp.hpp"

void ScrollTextApp::display_text(const char *tet,
                                 pimoroni::CosmicUnicorn &cosmic_unicorn,
                                 pimoroni::PicoGraphics_PenRGB888 &graphics)
{
    constexpr int TEXT_HEIGHT = 7;
    constexpr double TEXT_SCALE = 0.55;

    std::istringstream iss(tet);
    std::string line;

    graphics.set_pen(0, 0, 0);
    graphics.clear();

    int y = 0;
    while (std::getline(iss, line, '_')) {

        int32_t line_width = graphics.measure_text(line, TEXT_SCALE);
        printf("line_width: %d\n", line_width);

        graphics.set_pen(32, 32, 32);
        graphics.text(line, pimoroni::Point(0, y), -1, TEXT_SCALE);

        y += TEXT_HEIGHT;
    }

    cosmic_unicorn.update(&graphics);
}
