#include "startup_task.h"

int sb = 0;
void startup_task_entry(void* args)
{
    for(;;)
    {
        sb++;
    }
}