#include <cstdio>
#include <iostream>
using namespace std;

#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"


#include "libraries/pico_graphics/pico_graphics.hpp"
#include "cosmic_unicorn.hpp"
using namespace pimoroni;

#include "images/oi.h"
#include "images/babi.h"
#include "images/clear.h"
#include "cosmic/CosmicUnicornDisplayAgent.hpp"
#include "CLIAgent.hpp"
#include "MQTTAgent.hpp"

CosmicUnicornDisplayAgent ledsAgent;
CLIAgent cliAgent(ledsAgent);
MQTTAgent mqtt_agent(ledsAgent);

int main()
{
    stdio_init_all();
    sleep_ms(2000);
    printf("Starting unicorn-fun...\n");

    //Start tasks and scheduler
    printf("Starting FreeRTOS on core 0:\n");

    ledsAgent.start();
    cliAgent.start();
    mqtt_agent.start();

    vTaskStartScheduler();

    return 0;
}
