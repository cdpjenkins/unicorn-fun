#include "ImageApp.hpp"

#include "CosmicUnicornDisplayAgent.hpp"

void ImageApp::update(pimoroni::PicoGraphics_PenRGB888 &graphics) {

}

void ImageApp::plot_pixel(const pimoroni::Point &point, uint8_t red, uint8_t green, uint8_t blue,
                          pimoroni::PicoGraphics &graphics) const {
    int brightness = 16;

    int r = ((int)red * brightness) / 256;
    int g = ((int)green * brightness) / 256;
    int b = ((int)blue  * brightness) / 256;

    graphics.set_pen(r, g, b);
    graphics.pixel(point);
}

void ImageApp::draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const {
    const uint8_t *p = current_image;

    if (p != nullptr) {
        for (int y = 0; y < CosmicUnicornDisplayAgent::WIDTH; y++) {
            for (int x = 0; x < CosmicUnicornDisplayAgent::HEIGHT; x++) {
                uint8_t r = *p++;
                uint8_t g = *p++;
                uint8_t b = *p++;

                plot_pixel(pimoroni::Point(x, y), r, g, b, graphics);
            }
        }
    }

    cosmic_unicorn.update(&graphics);
}

void ImageApp::set_image(const uint8_t *image) {
    this->current_image = image;
}
