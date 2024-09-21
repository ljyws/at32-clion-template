#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

/* FreeRTOS的基本配置 */
#define configUSE_PREEMPTION                 1
#define configUSE_IDLE_HOOK                  0
#define configUSE_TICK_HOOK                  0
#define configCPU_CLOCK_HZ                   ( ( unsigned long ) 288000000 )  // CPU时钟频率
#define configTICK_RATE_HZ                   ( ( TickType_t ) 1000 )          // Tick频率
#define configMAX_PRIORITIES                 ( 24 )                             // 最大优先级数
#define configMINIMAL_STACK_SIZE             ( ( unsigned short ) 128 )       // 最小堆栈大小
#define configTOTAL_HEAP_SIZE                ( ( size_t ) ( 32 * 1024 ) )    // 总堆大小
#define configMAX_TASK_NAME_LEN              ( 16 )                            // 任务名称最大长度
#define configUSE_TRACE_FACILITY             1
#define configUSE_16_BIT_TICKS               0
#define configIDLE_SHOULD_YIELD              1
#define INCLUDE_vTaskDelay									 1					//启用delay

/* 中断优先级配置 */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	0x10  // 可通过系统调用的最大中断优先级
#define configKERNEL_INTERRUPT_PRIORITY       0 	// 内核中断优先级

/* 定义任务数量 */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5

/* 其他配置 */
#define configUSE_MUTEXES                     1
#define configUSE_RECURSIVE_MUTEXES           1
#define configUSE_COUNTING_SEMAPHORES         1
#define configUSE_QUEUE_SETS                  1
#define configGENERATE_RUN_TIME_STATS         0

/* 定义调试和跟踪 */
#define configASSERT(x)                       if ((x) == 0) { taskDISABLE_INTERRUPTS(); for( ;; ); }


#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler
#endif /* FREERTOS_CONFIG_H */
