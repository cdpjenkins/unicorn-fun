#ifndef UNICORN_FUN_MQTTAGENT_HPP
#define UNICORN_FUN_MQTTAGENT_HPP

#include "pico/cyw43_arch.h"
#include "lwip/apps/mqtt.h"

class MQTTAgent : public Agent {
public:
    explicit MQTTAgent();

    [[noreturn]]
    void task_main() override;
private:
};

#endif //UNICORN_FUN_MQTTAGENT_HPP
