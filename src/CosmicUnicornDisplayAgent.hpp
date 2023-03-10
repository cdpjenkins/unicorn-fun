#ifndef HELLO_FREERTOS_PICO_LEDSAGENT_HPP
#define HELLO_FREERTOS_PICO_LEDSAGENT_HPP

#include <queue.h>
#include <task.h>
#include <portmacro.h>

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"

#include "Agent.hpp"

struct CosmicUnicornDisplayCommand {
    explicit CosmicUnicornDisplayCommand() : pixels(nullptr) {}
    explicit CosmicUnicornDisplayCommand(const unsigned char *string) : pixels(string) {}

    const unsigned char* pixels;
};

class CosmicUnicornDisplayAgent : public Agent {
public:
    CosmicUnicornDisplayAgent();

    static const int WIDTH = 32;
    static const int HEIGHT = 32;

    void send(CosmicUnicornDisplayCommand *pCommand);

    [[noreturn]]
    void task_main() override;

private:
    static const UBaseType_t TASK_PRIORITY = tskIDLE_PRIORITY + 1UL;

    pimoroni::PicoGraphics_PenRGB888 graphics{WIDTH, HEIGHT, nullptr};
    pimoroni::CosmicUnicorn cosmic_unicorn;

protected:
    QueueHandle_t command_queue;

    void display_image(const uint8_t image[3072]);
};

#endif //HELLO_FREERTOS_PICO_LEDSAGENT_HPP
