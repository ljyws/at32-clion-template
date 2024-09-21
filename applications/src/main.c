#include "at32f435_437_clock.h"
#include "freertos_main.h"

int main(void)
{
    system_clock_config();

    startup_task_create();

    vTaskStartScheduler();

    while(1)
    {

    }
}



