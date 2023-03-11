#ifndef HELLO_FREERTOS_PICO_COMMANDINTERPRETERAGENT_HPP
#define HELLO_FREERTOS_PICO_COMMANDINTERPRETERAGENT_HPP

#include <message_buffer.h>
#include "Agent.hpp"
#include "CosmicUnicornDisplayAgent.hpp"

class CommandInterpreterAgent : public Agent {
public:
    CommandInterpreterAgent(CosmicUnicornDisplayAgent &agent);

    [[noreturn]]
    void task_main() override;
    void send_command(char *command_string);

private:
    MessageBufferHandle_t message_buffer;
    CosmicUnicornDisplayAgent &cosmic_unicorn_agent;

    void send_image_command(const uint8_t *image);
    void send_clear_command();
    void send_text_command(std::string text);
};


#endif //HELLO_FREERTOS_PICO_COMMANDINTERPRETERAGENT_HPP
