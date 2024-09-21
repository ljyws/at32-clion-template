#ifndef __STARTUP_TASK_H__
#define __STARTUP_TASK_H__

#ifdef __cplusplus
extern "C" {
#endif



/* includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"

#include "task.h"
/* exported types ------------------------------------------------------------*/
/* exported constants --------------------------------------------------------*/
/* exported macro ------------------------------------------------------------*/
/* exported functions ------------------------------------------------------- */



void startup_task_entry(void* args);


#ifdef __cplusplus
}
#endif

#endif

