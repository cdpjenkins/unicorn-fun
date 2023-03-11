#ifndef UNICORN_FUN_MQTTAGENT_HPP
#define UNICORN_FUN_MQTTAGENT_HPP

class MQTTAgent : public Agent {
public:
    explicit MQTTAgent();

    [[noreturn]]
    void task_main() override;
};


#endif //UNICORN_FUN_MQTTAGENT_HPP
