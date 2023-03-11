#ifndef HELLO_FREERTOS_PICO_LEDSAGENT_HPP
#define HELLO_FREERTOS_PICO_LEDSAGENT_HPP

#include <queue.h>
#include <task.h>
#include <portmacro.h>

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"

#include "Agent.hpp"

enum CommandType {
    NONE,
    CLEAR,
    DISPLAY_IMAGE
};

struct CosmicUnicornDisplayCommand {
    explicit CosmicUnicornDisplayCommand() :
        command_type(NONE),
        pixels(nullptr) {}

    explicit CosmicUnicornDisplayCommand(const CommandType command_type, const unsigned char *pixels) :
        command_type(command_type),
        pixels(pixels) {}

    const CommandType command_type;
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
    void clear_display();
};

#endif //HELLO_FREERTOS_PICO_LEDSAGENT_HPP
