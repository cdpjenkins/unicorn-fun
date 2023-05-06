#ifndef UNICORN_FUN_IMAGEAPP_HPP
#define UNICORN_FUN_IMAGEAPP_HPP


#include "App.hpp"

class ImageApp : public App {
public:
    void update(pimoroni::PicoGraphics_PenRGB888 &graphics);
    void draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const;

    void set_image(const uint8_t *image);

protected:
    void plot_pixel(const pimoroni::Point &point, uint8_t red, uint8_t green, uint8_t blue,
                              pimoroni::PicoGraphics &graphics) const;
private:
    const uint8_t *current_image = 0;
};


#endif //UNICORN_FUN_IMAGEAPP_HPP
