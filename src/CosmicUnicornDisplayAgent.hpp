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
    TEXT
};

struct ClearCommandBody {
    uint8_t value;
};

struct DisplayImageCommandBody {
    uint8_t *image;
};

struct TextCommand {
    char text[64];
};

union CommandBody {
    ClearCommandBody clear_command;
    DisplayImageCommandBody display_image_command;
    TextCommand text_command;

    void init_clear_command(uint8_t value) {
        this->clear_command.value = value;
    }

    void init_display_image_command(const uint8_t *image) {
        this->display_image_command.image = (uint8_t *)image;
    }

    void init_text_command(const char *text) {
        strlcpy((char *)this->text_command.text, (char *)text, sizeof(this->text_command.text));
    }
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

protected:
    QueueHandle_t command_queue;

    void display_image(const uint8_t image[3072]);
    void clear_display();

    void display_text(char *text_cstr);
};

#endif //HELLO_FREERTOS_PICO_LEDSAGENT_HPP
