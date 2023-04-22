################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ARM_DSP/Source/TransformFunctions/TransformFunctionsF16.c \
../ARM_DSP/Source/TransformFunctions/arm_bitreversal.c \
../ARM_DSP/Source/TransformFunctions/arm_bitreversal2.c \
../ARM_DSP/Source/TransformFunctions/arm_bitreversal_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_f64.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_init_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_init_f64.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_init_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_init_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_dct4_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_dct4_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_dct4_init_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_dct4_init_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_dct4_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_dct4_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_mfcc_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f64.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f16.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_init_f32.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_init_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_init_q31.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_q15.c \
../ARM_DSP/Source/TransformFunctions/arm_rfft_q31.c 

OBJS += \
./ARM_DSP/Source/TransformFunctions/TransformFunctionsF16.o \
./ARM_DSP/Source/TransformFunctions/arm_bitreversal.o \
./ARM_DSP/Source/TransformFunctions/arm_bitreversal2.o \
./ARM_DSP/Source/TransformFunctions/arm_bitreversal_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_f64.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f64.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_dct4_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_dct4_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_dct4_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_dct4_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f64.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f16.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_init_f32.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q31.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_q15.o \
./ARM_DSP/Source/TransformFunctions/arm_rfft_q31.o 

C_DEPS += \
./ARM_DSP/Source/TransformFunctions/TransformFunctionsF16.d \
./ARM_DSP/Source/TransformFunctions/arm_bitreversal.d \
./ARM_DSP/Source/TransformFunctions/arm_bitreversal2.d \
./ARM_DSP/Source/TransformFunctions/arm_bitreversal_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_f64.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f64.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_dct4_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_dct4_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_dct4_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_dct4_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_mfcc_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f64.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f16.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_init_f32.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q31.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_q15.d \
./ARM_DSP/Source/TransformFunctions/arm_rfft_q31.d 


# Each subdirectory must supply rules for building sources it contributes
ARM_DSP/Source/TransformFunctions/%.o ARM_DSP/Source/TransformFunctions/%.su: ../ARM_DSP/Source/TransformFunctions/%.c ARM_DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM7 -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/Include" -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/PrivateInclude" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ARM_DSP-2f-Source-2f-TransformFunctions

clean-ARM_DSP-2f-Source-2f-TransformFunctions:
	-$(RM) ./ARM_DSP/Source/TransformFunctions/TransformFunctionsF16.d ./ARM_DSP/Source/TransformFunctions/TransformFunctionsF16.o ./ARM_DSP/Source/TransformFunctions/TransformFunctionsF16.su ./ARM_DSP/Source/TransformFunctions/arm_bitreversal.d ./ARM_DSP/Source/TransformFunctions/arm_bitreversal.o ./ARM_DSP/Source/TransformFunctions/arm_bitreversal.su ./ARM_DSP/Source/TransformFunctions/arm_bitreversal2.d ./ARM_DSP/Source/TransformFunctions/arm_bitreversal2.o ./ARM_DSP/Source/TransformFunctions/arm_bitreversal2.su ./ARM_DSP/Source/TransformFunctions/arm_bitreversal_f16.d ./ARM_DSP/Source/TransformFunctions/arm_bitreversal_f16.o ./ARM_DSP/Source/TransformFunctions/arm_bitreversal_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_f32.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_f64.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_f64.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_f64.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f64.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f64.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_f64.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q15.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q15.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q15.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q31.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q31.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_init_q31.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_q15.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_q15.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_q15.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_q31.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_q31.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_q31.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_f32.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q15.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix2_q31.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_f32.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q15.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix4_q31.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f16.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f16.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f16.su ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o ./ARM_DSP/Source/TransformFunctions/arm_cfft_radix8_f32.su ./ARM_DSP/Source/TransformFunctions/arm_dct4_f32.d ./ARM_DSP/Source/TransformFunctions/arm_dct4_f32.o ./ARM_DSP/Source/TransformFunctions/arm_dct4_f32.su ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q15.d
	-$(RM) ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q15.o ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q15.su ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q31.d ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q31.o ./ARM_DSP/Source/TransformFunctions/arm_dct4_init_q31.su ./ARM_DSP/Source/TransformFunctions/arm_dct4_q15.d ./ARM_DSP/Source/TransformFunctions/arm_dct4_q15.o ./ARM_DSP/Source/TransformFunctions/arm_dct4_q15.su ./ARM_DSP/Source/TransformFunctions/arm_dct4_q31.d ./ARM_DSP/Source/TransformFunctions/arm_dct4_q31.o ./ARM_DSP/Source/TransformFunctions/arm_dct4_q31.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_f16.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_f16.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_f16.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_f32.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_f32.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_f32.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f16.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f16.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f16.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q15.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q15.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q15.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q31.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q31.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_init_q31.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_q15.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_q15.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_q15.su ./ARM_DSP/Source/TransformFunctions/arm_mfcc_q31.d ./ARM_DSP/Source/TransformFunctions/arm_mfcc_q31.o ./ARM_DSP/Source/TransformFunctions/arm_mfcc_q31.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_f32.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_f32.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_f32.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f16.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f16.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f16.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f32.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f32.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f32.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f64.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f64.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_f64.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f16.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f16.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f16.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_f32.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_f32.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_f32.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q15.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q15.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q15.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q31.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q31.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_init_q31.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_q15.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_q15.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_q15.su ./ARM_DSP/Source/TransformFunctions/arm_rfft_q31.d ./ARM_DSP/Source/TransformFunctions/arm_rfft_q31.o ./ARM_DSP/Source/TransformFunctions/arm_rfft_q31.su

.PHONY: clean-ARM_DSP-2f-Source-2f-TransformFunctions

