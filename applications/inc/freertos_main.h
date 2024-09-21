#ifndef __FREERTOS_MAIN_H__
#define __FREERTOS_MAIN_H__

#include "FreeRTOS.h"
#include "task.h"

#include "startup_task.h"

#define        START_TASK_STACK_SIZE    256       //定义堆栈大小为128字（1字等于4字节）
#define        START_TASK_PRIO          15        //定义任务优先级，0-31根据任务需求
extern TaskHandle_t   start_task_handler;              //定义任务句柄（结构体指针）



void startup_task_create();


#endif
