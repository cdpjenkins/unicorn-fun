#ifndef UNICORN_FUN_WITHMUTEXLOCK_HPP
#define UNICORN_FUN_WITHMUTEXLOCK_HPP

#include "FreeRTOS.h"
#include <semphr.h>

class WithMutexLock {
public:
    WithMutexLock(SemaphoreHandle_t message_buffer_mutex);
    ~WithMutexLock();

    bool mutex_acquired() {
        return rc;
    }

private:
    SemaphoreHandle_t message_buffer_mutex;
    BaseType_t rc;
};


#endif //UNICORN_FUN_WITHMUTEXLOCK_HPP
