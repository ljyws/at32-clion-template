#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
cmake_minimum_required(VERSION 3.27)

# 设置交叉编译工具链
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 指定交叉编译工具链
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# 设置项目名称
project(at32-clion-template LANGUAGES C CXX ASM)

# 设置 CMake 的 C 和 C++ 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# cpu内核参数设置
set(
        MCU
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
)

# 添加宏定义
add_definitions(
        -DAT32F435CGT7
        -DAT_START_F435_V1
        -DUSE_STDPERIPH_DRIVER
)


# 编译选项
add_compile_options(
        ${MCU}
        -g3 -O0
        -ffunction-sections -fdata-sections
)

# 设置链接器选项
set(LINKER_SCRIPT  ${CMAKE_SOURCE_DIR}/applications/misc/AT32F435xG_FLASH.ld)
add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_NAME}.map)
add_link_options(${MCU})
add_link_options(-specs=nano.specs -specs=nosys.specs -u _printf_float)


# 添加头文件路径，即.h文件
include_directories(
        ${CMAKE_SOURCE_DIR}/applications/inc
        ${CMAKE_SOURCE_DIR}/bsp/inc
        ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/core_support
        ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/device_support
        ${CMAKE_SOURCE_DIR}/libraries/drivers/inc
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/include
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/portable/GCC/ARM_CM4F

)

# 添加源文件

# 基本的文件
set(BASE_SOURCES
        ${CMAKE_SOURCE_DIR}/applications/src/main.c
        ${CMAKE_SOURCE_DIR}/applications/src/at32f435_437_clock.c
        ${CMAKE_SOURCE_DIR}/applications/src/at32f435_437_int.c
        ${CMAKE_SOURCE_DIR}/applications/src/startup_at32f435_437.s
        ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/device_support/system_at32f435_437.c
)

# 外设驱动文件
file(GLOB Peripheral_SOURCES
        ${CMAKE_SOURCE_DIR}/applications/src/*.c
        ${CMAKE_SOURCE_DIR}/bsp/src/*.c
        ${CMAKE_SOURCE_DIR}/libraries/drivers/src/*.c

)

# RTOS驱动文件
file(GLOB RTOS_SOURCES
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/croutine.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/event_groups.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/list.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/queue.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/stream_buffer.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/tasks.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/timers.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/portable/GCC/ARM_CM4F/port.c
        ${CMAKE_SOURCE_DIR}/middlewares/FreeRTOS/portable/MemMang/heap_4.c
)

list(APPEND SOURCES ${BASE_SOURCES} ${Peripheral_SOURCES} ${RTOS_SOURCES})

# 创建可执行文件
add_executable(${PROJECT_NAME}.elf ${SOURCES})

# 添加链接器脚本
target_link_options(${PROJECT_NAME}.elf PRIVATE -T ${LINKER_SCRIPT})

# 生成bin和hex命令
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.bin
        COMMENT "Generating HEX and BIN files from ELF"
)

# 清除所有生成的文件
add_custom_target(clean-all
        COMMAND ${CMAKE_COMMAND} -E remove  ${PROJECT_NAME}.bin
        COMMAND ${CMAKE_COMMAND} -E remove  ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_COMMAND} -E remove  ${PROJECT_NAME}.map
        COMMENT "Cleaning bin and hex files"
)