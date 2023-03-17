#include "WithMutexLock.hpp"

WithMutexLock::WithMutexLock(SemaphoreHandle_t message_buffer_mutex) : message_buffer_mutex(message_buffer_mutex) {
    rc = xSemaphoreTake(message_buffer_mutex, 10);
}

WithMutexLock::~WithMutexLock() {
    xSemaphoreGive(message_buffer_mutex);
}
