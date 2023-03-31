#ifndef UNICORN_FUN_SCROLLTEXTAPP_HPP
#define UNICORN_FUN_SCROLLTEXTAPP_HPP

#include <string>

#include <cosmic_unicorn.hpp>

class ScrollTextApp {
public:
    ScrollTextApp();
    void display_text(const char *text, pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics);
    void set_text(const char *text);
    void update(pimoroni::PicoGraphics_PenRGB888 &graphics);
    void draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const;

private:
    std::string text;
    int scroll_displacement;

    static constexpr double TEXT_SCALE = 0.55;
};


#endif //UNICORN_FUN_SCROLLTEXTAPP_HPP
