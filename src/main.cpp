#include <cstdio>

#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"

#include "oi.h"
#include "babi.h"
#include "clear.h"
#include "CosmicUnicornDisplayAgent.hpp"
#include "CLIAgent.hpp"
#include "CommandInterpreterAgent.hpp"

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"
using namespace pimoroni;


int main()
{
    stdio_init_all();
    sleep_ms(2000);
    printf("Starting unicorn-fun...\n");

    printf("sizeof PicoGraphics_PenRGB888: %d\n", sizeof(PicoGraphics_PenRGB888));
    printf("sizeof CosmicUnicorn: %d\n", sizeof(CosmicUnicorn));

    sleep_ms(10000);

    //Start tasks and scheduler
    const char *rtos_name = "FreeRTOS";
    printf("Starting %s on core 0:\n", rtos_name);
    CosmicUnicornDisplayAgent ledsAgent;
    ledsAgent.start();

    CommandInterpreterAgent commandInterpreterAgent(ledsAgent);
    commandInterpreterAgent.start();

    CLIAgent cliAgent(ledsAgent, commandInterpreterAgent);
    cliAgent.start();

    vTaskStartScheduler();

    return 0;
}
