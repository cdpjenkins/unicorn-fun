#include "WithMutexLock.hpp"

WithMutexLock::WithMutexLock(SemaphoreHandle_t message_buffer_mutex) : message_buffer_mutex(message_buffer_mutex) {
    rc = 0;
}

WithMutexLock::~WithMutexLock() {
    xSemaphoreGive(message_buffer_mutex);
}

bool WithMutexLock::lock() {
    rc = xSemaphoreTake(message_buffer_mutex, 10);

    return rc;
}
