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
    CosmicUnicornDisplayAgent &leds_agent;
};


#endif //HELLO_FREERTOS_PICO_COMMANDINTERPRETERAGENT_HPP
