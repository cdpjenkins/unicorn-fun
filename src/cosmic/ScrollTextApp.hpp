#ifndef UNICORN_FUN_SCROLLTEXTAPP_HPP
#define UNICORN_FUN_SCROLLTEXTAPP_HPP


#include <cosmic_unicorn.hpp>

class ScrollTextApp {
public:
    ScrollTextApp();
    void display_text(const char *text, pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics);

private:
    int scroll_displacement;
};


#endif //UNICORN_FUN_SCROLLTEXTAPP_HPP
