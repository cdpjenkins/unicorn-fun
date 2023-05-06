#ifndef UNICORN_FUN_APP_HPP
#define UNICORN_FUN_APP_HPP

#include <pico_graphics.hpp>
#include <cosmic_unicorn.hpp>

class App {
public:
    virtual void update(pimoroni::PicoGraphics_PenRGB888 &graphics) =0;
    virtual void draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const =0;
};


#endif //UNICORN_FUN_APP_HPP
