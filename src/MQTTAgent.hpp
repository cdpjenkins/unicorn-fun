#ifndef UNICORN_FUN_MQTTAGENT_HPP
#define UNICORN_FUN_MQTTAGENT_HPP

#include "pico/cyw43_arch.h"
#include "lwip/apps/mqtt.h"

class MQTTAgent : public Agent {
public:
    explicit MQTTAgent();

    [[noreturn]]
    void task_main() override;

    void incoming_publish_cb(const char *topic, u32_t tot_len);

private:
};

#endif //UNICORN_FUN_MQTTAGENT_HPP
