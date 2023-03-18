#include "FreeRTOS.h"

#include <cstdio>

#include "CLIAgent.hpp"
#include "cosmic/CosmicUnicornDisplayAgent.hpp"

CLIAgent::CLIAgent(CosmicUnicornDisplayAgent &agent) :
        Agent("cli_task",
          configMINIMAL_STACK_SIZE * 2,
          TASK_PRIORITY),
        cosmis_unicorn_agent(agent)
{

}

void CLIAgent::task_main() {
    while (true) {
        char line[256];

        printf("$ ");

        char latest_char = '\0';
        for (char *cursor = line; latest_char != '\r'; ) {
            int aChar = getchar();
            printf("%c", aChar);
            latest_char = aChar;
            if (latest_char == '\r') {
                *cursor++ = '\0';
            } else {
                *cursor++ = latest_char;
            }
        }
        printf("\n");

        cosmis_unicorn_agent.send_command(line);
    }
}
