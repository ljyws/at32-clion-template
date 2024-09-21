#include "freertos_main.h"



TaskHandle_t   start_task_handler;
void startup_task_create()
{
    xTaskCreate(
            (TaskFunction_t)            startup_task_entry,
            (char *)                    "startup_task",
            (configSTACK_DEPTH_TYPE)    START_TASK_STACK_SIZE,
            (void *)                    NULL,
            (UBaseType_t)               START_TASK_PRIO,
            (TaskHandle_t *)            &start_task_handler
            );
}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    for(;;)
    {
        /* Stay in an infinite loop to halt the system */
    }
}
