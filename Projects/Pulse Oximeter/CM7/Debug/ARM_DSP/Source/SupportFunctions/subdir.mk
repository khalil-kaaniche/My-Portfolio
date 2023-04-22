################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ARM_DSP/Source/SupportFunctions/SupportFunctionsF16.c \
../ARM_DSP/Source/SupportFunctions/arm_barycenter_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_barycenter_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_bitonic_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_bubble_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_copy_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_copy_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_copy_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_copy_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_copy_q31.c \
../ARM_DSP/Source/SupportFunctions/arm_copy_q7.c \
../ARM_DSP/Source/SupportFunctions/arm_f16_to_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_f16_to_float.c \
../ARM_DSP/Source/SupportFunctions/arm_f16_to_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_f64_to_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_f64_to_float.c \
../ARM_DSP/Source/SupportFunctions/arm_f64_to_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_f64_to_q31.c \
../ARM_DSP/Source/SupportFunctions/arm_f64_to_q7.c \
../ARM_DSP/Source/SupportFunctions/arm_fill_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_fill_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_fill_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_fill_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_fill_q31.c \
../ARM_DSP/Source/SupportFunctions/arm_fill_q7.c \
../ARM_DSP/Source/SupportFunctions/arm_float_to_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_float_to_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_float_to_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_float_to_q31.c \
../ARM_DSP/Source/SupportFunctions/arm_float_to_q7.c \
../ARM_DSP/Source/SupportFunctions/arm_heap_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_insertion_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_merge_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_merge_sort_init_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_q15_to_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_q15_to_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_q15_to_float.c \
../ARM_DSP/Source/SupportFunctions/arm_q15_to_q31.c \
../ARM_DSP/Source/SupportFunctions/arm_q15_to_q7.c \
../ARM_DSP/Source/SupportFunctions/arm_q31_to_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_q31_to_float.c \
../ARM_DSP/Source/SupportFunctions/arm_q31_to_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_q31_to_q7.c \
../ARM_DSP/Source/SupportFunctions/arm_q7_to_f64.c \
../ARM_DSP/Source/SupportFunctions/arm_q7_to_float.c \
../ARM_DSP/Source/SupportFunctions/arm_q7_to_q15.c \
../ARM_DSP/Source/SupportFunctions/arm_q7_to_q31.c \
../ARM_DSP/Source/SupportFunctions/arm_quick_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_selection_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_sort_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_sort_init_f32.c \
../ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f16.c \
../ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f32.c 

OBJS += \
./ARM_DSP/Source/SupportFunctions/SupportFunctionsF16.o \
./ARM_DSP/Source/SupportFunctions/arm_barycenter_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_barycenter_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_bitonic_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_bubble_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_copy_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_copy_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_copy_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_copy_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_copy_q31.o \
./ARM_DSP/Source/SupportFunctions/arm_copy_q7.o \
./ARM_DSP/Source/SupportFunctions/arm_f16_to_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_f16_to_float.o \
./ARM_DSP/Source/SupportFunctions/arm_f16_to_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_float.o \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_q31.o \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_q7.o \
./ARM_DSP/Source/SupportFunctions/arm_fill_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_fill_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_fill_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_fill_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_fill_q31.o \
./ARM_DSP/Source/SupportFunctions/arm_fill_q7.o \
./ARM_DSP/Source/SupportFunctions/arm_float_to_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_float_to_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_float_to_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_float_to_q31.o \
./ARM_DSP/Source/SupportFunctions/arm_float_to_q7.o \
./ARM_DSP/Source/SupportFunctions/arm_heap_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_insertion_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_merge_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_merge_sort_init_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_float.o \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_q31.o \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_q7.o \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_float.o \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_q7.o \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_f64.o \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_float.o \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_q15.o \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_q31.o \
./ARM_DSP/Source/SupportFunctions/arm_quick_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_selection_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_sort_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_sort_init_f32.o \
./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f16.o \
./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f32.o 

C_DEPS += \
./ARM_DSP/Source/SupportFunctions/SupportFunctionsF16.d \
./ARM_DSP/Source/SupportFunctions/arm_barycenter_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_barycenter_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_bitonic_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_bubble_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_copy_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_copy_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_copy_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_copy_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_copy_q31.d \
./ARM_DSP/Source/SupportFunctions/arm_copy_q7.d \
./ARM_DSP/Source/SupportFunctions/arm_f16_to_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_f16_to_float.d \
./ARM_DSP/Source/SupportFunctions/arm_f16_to_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_float.d \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_q31.d \
./ARM_DSP/Source/SupportFunctions/arm_f64_to_q7.d \
./ARM_DSP/Source/SupportFunctions/arm_fill_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_fill_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_fill_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_fill_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_fill_q31.d \
./ARM_DSP/Source/SupportFunctions/arm_fill_q7.d \
./ARM_DSP/Source/SupportFunctions/arm_float_to_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_float_to_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_float_to_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_float_to_q31.d \
./ARM_DSP/Source/SupportFunctions/arm_float_to_q7.d \
./ARM_DSP/Source/SupportFunctions/arm_heap_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_insertion_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_merge_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_merge_sort_init_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_float.d \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_q31.d \
./ARM_DSP/Source/SupportFunctions/arm_q15_to_q7.d \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_float.d \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_q31_to_q7.d \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_f64.d \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_float.d \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_q15.d \
./ARM_DSP/Source/SupportFunctions/arm_q7_to_q31.d \
./ARM_DSP/Source/SupportFunctions/arm_quick_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_selection_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_sort_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_sort_init_f32.d \
./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f16.d \
./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f32.d 


# Each subdirectory must supply rules for building sources it contributes
ARM_DSP/Source/SupportFunctions/%.o ARM_DSP/Source/SupportFunctions/%.su: ../ARM_DSP/Source/SupportFunctions/%.c ARM_DSP/Source/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM7 -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/Include" -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/PrivateInclude" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ARM_DSP-2f-Source-2f-SupportFunctions

clean-ARM_DSP-2f-Source-2f-SupportFunctions:
	-$(RM) ./ARM_DSP/Source/SupportFunctions/SupportFunctionsF16.d ./ARM_DSP/Source/SupportFunctions/SupportFunctionsF16.o ./ARM_DSP/Source/SupportFunctions/SupportFunctionsF16.su ./ARM_DSP/Source/SupportFunctions/arm_barycenter_f16.d ./ARM_DSP/Source/SupportFunctions/arm_barycenter_f16.o ./ARM_DSP/Source/SupportFunctions/arm_barycenter_f16.su ./ARM_DSP/Source/SupportFunctions/arm_barycenter_f32.d ./ARM_DSP/Source/SupportFunctions/arm_barycenter_f32.o ./ARM_DSP/Source/SupportFunctions/arm_barycenter_f32.su ./ARM_DSP/Source/SupportFunctions/arm_bitonic_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_bitonic_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_bitonic_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_bubble_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_bubble_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_bubble_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_copy_f16.d ./ARM_DSP/Source/SupportFunctions/arm_copy_f16.o ./ARM_DSP/Source/SupportFunctions/arm_copy_f16.su ./ARM_DSP/Source/SupportFunctions/arm_copy_f32.d ./ARM_DSP/Source/SupportFunctions/arm_copy_f32.o ./ARM_DSP/Source/SupportFunctions/arm_copy_f32.su ./ARM_DSP/Source/SupportFunctions/arm_copy_f64.d ./ARM_DSP/Source/SupportFunctions/arm_copy_f64.o ./ARM_DSP/Source/SupportFunctions/arm_copy_f64.su ./ARM_DSP/Source/SupportFunctions/arm_copy_q15.d ./ARM_DSP/Source/SupportFunctions/arm_copy_q15.o ./ARM_DSP/Source/SupportFunctions/arm_copy_q15.su ./ARM_DSP/Source/SupportFunctions/arm_copy_q31.d ./ARM_DSP/Source/SupportFunctions/arm_copy_q31.o ./ARM_DSP/Source/SupportFunctions/arm_copy_q31.su ./ARM_DSP/Source/SupportFunctions/arm_copy_q7.d ./ARM_DSP/Source/SupportFunctions/arm_copy_q7.o ./ARM_DSP/Source/SupportFunctions/arm_copy_q7.su ./ARM_DSP/Source/SupportFunctions/arm_f16_to_f64.d ./ARM_DSP/Source/SupportFunctions/arm_f16_to_f64.o ./ARM_DSP/Source/SupportFunctions/arm_f16_to_f64.su ./ARM_DSP/Source/SupportFunctions/arm_f16_to_float.d ./ARM_DSP/Source/SupportFunctions/arm_f16_to_float.o ./ARM_DSP/Source/SupportFunctions/arm_f16_to_float.su ./ARM_DSP/Source/SupportFunctions/arm_f16_to_q15.d ./ARM_DSP/Source/SupportFunctions/arm_f16_to_q15.o ./ARM_DSP/Source/SupportFunctions/arm_f16_to_q15.su ./ARM_DSP/Source/SupportFunctions/arm_f64_to_f16.d ./ARM_DSP/Source/SupportFunctions/arm_f64_to_f16.o ./ARM_DSP/Source/SupportFunctions/arm_f64_to_f16.su ./ARM_DSP/Source/SupportFunctions/arm_f64_to_float.d ./ARM_DSP/Source/SupportFunctions/arm_f64_to_float.o ./ARM_DSP/Source/SupportFunctions/arm_f64_to_float.su ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q15.d ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q15.o ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q15.su ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q31.d ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q31.o ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q31.su ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q7.d ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q7.o ./ARM_DSP/Source/SupportFunctions/arm_f64_to_q7.su ./ARM_DSP/Source/SupportFunctions/arm_fill_f16.d ./ARM_DSP/Source/SupportFunctions/arm_fill_f16.o ./ARM_DSP/Source/SupportFunctions/arm_fill_f16.su ./ARM_DSP/Source/SupportFunctions/arm_fill_f32.d ./ARM_DSP/Source/SupportFunctions/arm_fill_f32.o ./ARM_DSP/Source/SupportFunctions/arm_fill_f32.su ./ARM_DSP/Source/SupportFunctions/arm_fill_f64.d ./ARM_DSP/Source/SupportFunctions/arm_fill_f64.o ./ARM_DSP/Source/SupportFunctions/arm_fill_f64.su ./ARM_DSP/Source/SupportFunctions/arm_fill_q15.d ./ARM_DSP/Source/SupportFunctions/arm_fill_q15.o ./ARM_DSP/Source/SupportFunctions/arm_fill_q15.su ./ARM_DSP/Source/SupportFunctions/arm_fill_q31.d ./ARM_DSP/Source/SupportFunctions/arm_fill_q31.o ./ARM_DSP/Source/SupportFunctions/arm_fill_q31.su ./ARM_DSP/Source/SupportFunctions/arm_fill_q7.d ./ARM_DSP/Source/SupportFunctions/arm_fill_q7.o ./ARM_DSP/Source/SupportFunctions/arm_fill_q7.su ./ARM_DSP/Source/SupportFunctions/arm_float_to_f16.d ./ARM_DSP/Source/SupportFunctions/arm_float_to_f16.o ./ARM_DSP/Source/SupportFunctions/arm_float_to_f16.su ./ARM_DSP/Source/SupportFunctions/arm_float_to_f64.d ./ARM_DSP/Source/SupportFunctions/arm_float_to_f64.o ./ARM_DSP/Source/SupportFunctions/arm_float_to_f64.su ./ARM_DSP/Source/SupportFunctions/arm_float_to_q15.d ./ARM_DSP/Source/SupportFunctions/arm_float_to_q15.o ./ARM_DSP/Source/SupportFunctions/arm_float_to_q15.su ./ARM_DSP/Source/SupportFunctions/arm_float_to_q31.d ./ARM_DSP/Source/SupportFunctions/arm_float_to_q31.o ./ARM_DSP/Source/SupportFunctions/arm_float_to_q31.su ./ARM_DSP/Source/SupportFunctions/arm_float_to_q7.d ./ARM_DSP/Source/SupportFunctions/arm_float_to_q7.o ./ARM_DSP/Source/SupportFunctions/arm_float_to_q7.su ./ARM_DSP/Source/SupportFunctions/arm_heap_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_heap_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_heap_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_insertion_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_insertion_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_insertion_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_merge_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_merge_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_merge_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_merge_sort_init_f32.d ./ARM_DSP/Source/SupportFunctions/arm_merge_sort_init_f32.o ./ARM_DSP/Source/SupportFunctions/arm_merge_sort_init_f32.su ./ARM_DSP/Source/SupportFunctions/arm_q15_to_f16.d ./ARM_DSP/Source/SupportFunctions/arm_q15_to_f16.o ./ARM_DSP/Source/SupportFunctions/arm_q15_to_f16.su ./ARM_DSP/Source/SupportFunctions/arm_q15_to_f64.d ./ARM_DSP/Source/SupportFunctions/arm_q15_to_f64.o ./ARM_DSP/Source/SupportFunctions/arm_q15_to_f64.su ./ARM_DSP/Source/SupportFunctions/arm_q15_to_float.d ./ARM_DSP/Source/SupportFunctions/arm_q15_to_float.o ./ARM_DSP/Source/SupportFunctions/arm_q15_to_float.su ./ARM_DSP/Source/SupportFunctions/arm_q15_to_q31.d ./ARM_DSP/Source/SupportFunctions/arm_q15_to_q31.o ./ARM_DSP/Source/SupportFunctions/arm_q15_to_q31.su
	-$(RM) ./ARM_DSP/Source/SupportFunctions/arm_q15_to_q7.d ./ARM_DSP/Source/SupportFunctions/arm_q15_to_q7.o ./ARM_DSP/Source/SupportFunctions/arm_q15_to_q7.su ./ARM_DSP/Source/SupportFunctions/arm_q31_to_f64.d ./ARM_DSP/Source/SupportFunctions/arm_q31_to_f64.o ./ARM_DSP/Source/SupportFunctions/arm_q31_to_f64.su ./ARM_DSP/Source/SupportFunctions/arm_q31_to_float.d ./ARM_DSP/Source/SupportFunctions/arm_q31_to_float.o ./ARM_DSP/Source/SupportFunctions/arm_q31_to_float.su ./ARM_DSP/Source/SupportFunctions/arm_q31_to_q15.d ./ARM_DSP/Source/SupportFunctions/arm_q31_to_q15.o ./ARM_DSP/Source/SupportFunctions/arm_q31_to_q15.su ./ARM_DSP/Source/SupportFunctions/arm_q31_to_q7.d ./ARM_DSP/Source/SupportFunctions/arm_q31_to_q7.o ./ARM_DSP/Source/SupportFunctions/arm_q31_to_q7.su ./ARM_DSP/Source/SupportFunctions/arm_q7_to_f64.d ./ARM_DSP/Source/SupportFunctions/arm_q7_to_f64.o ./ARM_DSP/Source/SupportFunctions/arm_q7_to_f64.su ./ARM_DSP/Source/SupportFunctions/arm_q7_to_float.d ./ARM_DSP/Source/SupportFunctions/arm_q7_to_float.o ./ARM_DSP/Source/SupportFunctions/arm_q7_to_float.su ./ARM_DSP/Source/SupportFunctions/arm_q7_to_q15.d ./ARM_DSP/Source/SupportFunctions/arm_q7_to_q15.o ./ARM_DSP/Source/SupportFunctions/arm_q7_to_q15.su ./ARM_DSP/Source/SupportFunctions/arm_q7_to_q31.d ./ARM_DSP/Source/SupportFunctions/arm_q7_to_q31.o ./ARM_DSP/Source/SupportFunctions/arm_q7_to_q31.su ./ARM_DSP/Source/SupportFunctions/arm_quick_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_quick_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_quick_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_selection_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_selection_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_selection_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_sort_f32.d ./ARM_DSP/Source/SupportFunctions/arm_sort_f32.o ./ARM_DSP/Source/SupportFunctions/arm_sort_f32.su ./ARM_DSP/Source/SupportFunctions/arm_sort_init_f32.d ./ARM_DSP/Source/SupportFunctions/arm_sort_init_f32.o ./ARM_DSP/Source/SupportFunctions/arm_sort_init_f32.su ./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f16.d ./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f16.o ./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f16.su ./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f32.d ./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f32.o ./ARM_DSP/Source/SupportFunctions/arm_weighted_sum_f32.su

.PHONY: clean-ARM_DSP-2f-Source-2f-SupportFunctions

