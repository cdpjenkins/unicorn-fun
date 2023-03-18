#ifndef HELLO_FREERTOS_PICO_CLIAGENT_HPP
#define HELLO_FREERTOS_PICO_CLIAGENT_HPP

#include "Agent.hpp"
#include "CosmicUnicornDisplayAgent.hpp"

class CLIAgent : public Agent {
public:
    CLIAgent(CosmicUnicornDisplayAgent &agent);

    [[noreturn]]
    void task_main() override;
private:
    CosmicUnicornDisplayAgent &cosmis_unicorn_agent;

    static const UBaseType_t TASK_PRIORITY = tskIDLE_PRIORITY + 1UL;
};


#endif //HELLO_FREERTOS_PICO_CLIAGENT_HPP
