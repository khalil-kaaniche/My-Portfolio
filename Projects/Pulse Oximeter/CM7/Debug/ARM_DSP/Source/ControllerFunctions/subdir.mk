################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ARM_DSP/Source/ControllerFunctions/arm_pid_init_f32.c \
../ARM_DSP/Source/ControllerFunctions/arm_pid_init_q15.c \
../ARM_DSP/Source/ControllerFunctions/arm_pid_init_q31.c \
../ARM_DSP/Source/ControllerFunctions/arm_pid_reset_f32.c \
../ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q15.c \
../ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q31.c \
../ARM_DSP/Source/ControllerFunctions/arm_sin_cos_f32.c \
../ARM_DSP/Source/ControllerFunctions/arm_sin_cos_q31.c 

OBJS += \
./ARM_DSP/Source/ControllerFunctions/arm_pid_init_f32.o \
./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q15.o \
./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q31.o \
./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_f32.o \
./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q15.o \
./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q31.o \
./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_f32.o \
./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_q31.o 

C_DEPS += \
./ARM_DSP/Source/ControllerFunctions/arm_pid_init_f32.d \
./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q15.d \
./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q31.d \
./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_f32.d \
./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q15.d \
./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q31.d \
./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_f32.d \
./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_q31.d 


# Each subdirectory must supply rules for building sources it contributes
ARM_DSP/Source/ControllerFunctions/%.o ARM_DSP/Source/ControllerFunctions/%.su: ../ARM_DSP/Source/ControllerFunctions/%.c ARM_DSP/Source/ControllerFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM7 -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/Include" -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/PrivateInclude" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ARM_DSP-2f-Source-2f-ControllerFunctions

clean-ARM_DSP-2f-Source-2f-ControllerFunctions:
	-$(RM) ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_f32.d ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_f32.o ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_f32.su ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q15.d ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q15.o ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q15.su ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q31.d ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q31.o ./ARM_DSP/Source/ControllerFunctions/arm_pid_init_q31.su ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_f32.d ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_f32.o ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_f32.su ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q15.d ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q15.o ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q15.su ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q31.d ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q31.o ./ARM_DSP/Source/ControllerFunctions/arm_pid_reset_q31.su ./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_f32.d ./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_f32.o ./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_f32.su ./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_q31.d ./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_q31.o ./ARM_DSP/Source/ControllerFunctions/arm_sin_cos_q31.su

.PHONY: clean-ARM_DSP-2f-Source-2f-ControllerFunctions

