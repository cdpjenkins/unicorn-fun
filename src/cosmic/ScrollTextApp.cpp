#include <iostream>
#include <sstream>
#include <string>

#include "ScrollTextApp.hpp"

ScrollTextApp::ScrollTextApp() :
    scroll_displacement{0}
{

}


void ScrollTextApp::display_text(const char *text,
                                 pimoroni::CosmicUnicorn &cosmic_unicorn,
                                 pimoroni::PicoGraphics_PenRGB888 &graphics)
{
    printf("displacement: %d\n", scroll_displacement);

    constexpr double TEXT_SCALE = 0.55;

    graphics.set_pen(0, 0, 0);
    graphics.clear();

    int32_t line_width = graphics.measure_text(text, TEXT_SCALE);
    printf("line_width: %d\n", line_width);

    graphics.set_pen(32, 32, 32);
    graphics.text(text, pimoroni::Point(scroll_displacement--, 5), -1, TEXT_SCALE);

    cosmic_unicorn.update(&graphics);

    if ((-scroll_displacement) > line_width) {
        scroll_displacement = pimoroni::CosmicUnicorn::WIDTH;
    }
}
