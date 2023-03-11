#ifndef HELLO_FREERTOS_PICO_LEDSAGENT_HPP
#define HELLO_FREERTOS_PICO_LEDSAGENT_HPP

#include <queue.h>
#include <task.h>
#include <portmacro.h>
#include <cstring>

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"

#include "Agent.hpp"

enum CommandType {
    NONE,
    CLEAR,
    DISPLAY_IMAGE,
    TEXT,
    BRIGHTNESS
};

struct ClearCommandBody {
    uint8_t value;

    void init(uint8_t value) {
        this->value = value;
    }
};

struct DisplayImageCommandBody {
    uint8_t *image;

    void init(const uint8_t *image) {
        this->image = (uint8_t *)image;
    }
};

struct TextCommand {
    char text[64];

    void init(const char *text) {
        strlcpy(this->text, text, sizeof(this->text));
    }
};

struct BrightnessCommand {
    uint8_t brightness;

    void init(const uint8_t brightness) {
        this->brightness = brightness;
    }
};

union CommandBody {
    ClearCommandBody clear_command;
    DisplayImageCommandBody display_image_command;
    TextCommand text_command;
    BrightnessCommand brightness_command;
};

struct CosmicUnicornDisplayCommand {
    const CommandType command_type;
    CommandBody body;

    explicit CosmicUnicornDisplayCommand() : CosmicUnicornDisplayCommand(NONE) {}

    explicit CosmicUnicornDisplayCommand(CommandType command_type) : command_type(command_type) {
        memset(&body, 0, sizeof(body));
    }
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

    uint8_t brightness;

protected:
    QueueHandle_t command_queue;

    void display_image(const uint8_t image[3072]);
    void clear_display();

    void display_text(char *text_cstr);

    void plot_pixel(const pimoroni::Point &point, uint8_t red, uint8_t green, uint8_t blue);
};

#endif //HELLO_FREERTOS_PICO_LEDSAGENT_HPP
