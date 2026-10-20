################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/Src/dispatcher.c \
../Custom/Src/finite_state_machine.c \
../Custom/Src/led_hardware_implementation.c \
../Custom/Src/mspc_event_queue.c 

OBJS += \
./Custom/Src/dispatcher.o \
./Custom/Src/finite_state_machine.o \
./Custom/Src/led_hardware_implementation.o \
./Custom/Src/mspc_event_queue.o 

C_DEPS += \
./Custom/Src/dispatcher.d \
./Custom/Src/finite_state_machine.d \
./Custom/Src/led_hardware_implementation.d \
./Custom/Src/mspc_event_queue.d 


# Each subdirectory must supply rules for building sources it contributes
Custom/Src/%.o Custom/Src/%.su Custom/Src/%.cyclo: ../Custom/Src/%.c Custom/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/mgt/Development/F407_001/Custom/Inc" -I"/Users/mgt/Development/F407_001/Custom/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Custom-2f-Src

clean-Custom-2f-Src:
	-$(RM) ./Custom/Src/dispatcher.cyclo ./Custom/Src/dispatcher.d ./Custom/Src/dispatcher.o ./Custom/Src/dispatcher.su ./Custom/Src/finite_state_machine.cyclo ./Custom/Src/finite_state_machine.d ./Custom/Src/finite_state_machine.o ./Custom/Src/finite_state_machine.su ./Custom/Src/led_hardware_implementation.cyclo ./Custom/Src/led_hardware_implementation.d ./Custom/Src/led_hardware_implementation.o ./Custom/Src/led_hardware_implementation.su ./Custom/Src/mspc_event_queue.cyclo ./Custom/Src/mspc_event_queue.d ./Custom/Src/mspc_event_queue.o ./Custom/Src/mspc_event_queue.su

.PHONY: clean-Custom-2f-Src

