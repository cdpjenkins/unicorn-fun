#ifndef UNICORN_FUN_CONWAYAPP_HPP
#define UNICORN_FUN_CONWAYAPP_HPP

#include "App.hpp"
#include "conway/ConwayGrid.hpp"

class ConwayApp : public App {
public:
    ConwayApp();
    void update(pimoroni::PicoGraphics_PenRGB888 &graphics);
    void draw(pimoroni::CosmicUnicorn &cosmic_unicorn, pimoroni::PicoGraphics_PenRGB888 &graphics) const;

    void add_hardcoded_glider();
private:
    ConwayGrid grid;

};


#endif //UNICORN_FUN_CONWAYAPP_HPP
