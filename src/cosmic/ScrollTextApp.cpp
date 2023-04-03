#include <iostream>
#include <sstream>
#include <string>

#include "ScrollTextApp.hpp"

ScrollTextApp::ScrollTextApp() :
    scroll_displacement{0},
    text("")
{

}


void ScrollTextApp::display_text(const char *text,
                                 pimoroni::CosmicUnicorn &cosmic_unicorn,
                                 pimoroni::PicoGraphics_PenRGB888 &graphics)
{
    printf("set_text: %s\n", text);

    set_text(text);
    update(graphics);
    draw(cosmic_unicorn, graphics);
}

void ScrollTextApp::draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const {
    if (text != "") {
//        printf("draw: %s\n", this->text.c_str());

        graphics.set_pen(0, 0, 0);
        graphics.clear();
        graphics.set_pen(32, 32, 32);
        graphics.text(this->text, pimoroni::Point(scroll_displacement, 5), -1, TEXT_SCALE);
        cosmic_unicorn.update(&graphics);
    }
}

void ScrollTextApp::update(pimoroni::PicoGraphics_PenRGB888 &graphics) {
    if (text != "") {
        int32_t line_width = graphics.measure_text(this->text, TEXT_SCALE);
        scroll_displacement--;
        if ((-scroll_displacement) > line_width) {
            scroll_displacement = pimoroni::CosmicUnicorn::WIDTH;
        }
    }
}

void ScrollTextApp::set_text(const char *text) {
    ScrollTextApp::text = text;

    scroll_displacement = pimoroni::CosmicUnicorn::WIDTH;
}
