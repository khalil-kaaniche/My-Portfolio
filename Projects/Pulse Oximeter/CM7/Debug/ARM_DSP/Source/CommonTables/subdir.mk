################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ARM_DSP/Source/CommonTables/CommonTablesF16.c \
../ARM_DSP/Source/CommonTables/arm_common_tables.c \
../ARM_DSP/Source/CommonTables/arm_common_tables_f16.c \
../ARM_DSP/Source/CommonTables/arm_const_structs.c \
../ARM_DSP/Source/CommonTables/arm_const_structs_f16.c \
../ARM_DSP/Source/CommonTables/arm_mve_tables.c \
../ARM_DSP/Source/CommonTables/arm_mve_tables_f16.c 

OBJS += \
./ARM_DSP/Source/CommonTables/CommonTablesF16.o \
./ARM_DSP/Source/CommonTables/arm_common_tables.o \
./ARM_DSP/Source/CommonTables/arm_common_tables_f16.o \
./ARM_DSP/Source/CommonTables/arm_const_structs.o \
./ARM_DSP/Source/CommonTables/arm_const_structs_f16.o \
./ARM_DSP/Source/CommonTables/arm_mve_tables.o \
./ARM_DSP/Source/CommonTables/arm_mve_tables_f16.o 

C_DEPS += \
./ARM_DSP/Source/CommonTables/CommonTablesF16.d \
./ARM_DSP/Source/CommonTables/arm_common_tables.d \
./ARM_DSP/Source/CommonTables/arm_common_tables_f16.d \
./ARM_DSP/Source/CommonTables/arm_const_structs.d \
./ARM_DSP/Source/CommonTables/arm_const_structs_f16.d \
./ARM_DSP/Source/CommonTables/arm_mve_tables.d \
./ARM_DSP/Source/CommonTables/arm_mve_tables_f16.d 


# Each subdirectory must supply rules for building sources it contributes
ARM_DSP/Source/CommonTables/%.o ARM_DSP/Source/CommonTables/%.su: ../ARM_DSP/Source/CommonTables/%.c ARM_DSP/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM7 -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/Include" -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/PrivateInclude" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ARM_DSP-2f-Source-2f-CommonTables

clean-ARM_DSP-2f-Source-2f-CommonTables:
	-$(RM) ./ARM_DSP/Source/CommonTables/CommonTablesF16.d ./ARM_DSP/Source/CommonTables/CommonTablesF16.o ./ARM_DSP/Source/CommonTables/CommonTablesF16.su ./ARM_DSP/Source/CommonTables/arm_common_tables.d ./ARM_DSP/Source/CommonTables/arm_common_tables.o ./ARM_DSP/Source/CommonTables/arm_common_tables.su ./ARM_DSP/Source/CommonTables/arm_common_tables_f16.d ./ARM_DSP/Source/CommonTables/arm_common_tables_f16.o ./ARM_DSP/Source/CommonTables/arm_common_tables_f16.su ./ARM_DSP/Source/CommonTables/arm_const_structs.d ./ARM_DSP/Source/CommonTables/arm_const_structs.o ./ARM_DSP/Source/CommonTables/arm_const_structs.su ./ARM_DSP/Source/CommonTables/arm_const_structs_f16.d ./ARM_DSP/Source/CommonTables/arm_const_structs_f16.o ./ARM_DSP/Source/CommonTables/arm_const_structs_f16.su ./ARM_DSP/Source/CommonTables/arm_mve_tables.d ./ARM_DSP/Source/CommonTables/arm_mve_tables.o ./ARM_DSP/Source/CommonTables/arm_mve_tables.su ./ARM_DSP/Source/CommonTables/arm_mve_tables_f16.d ./ARM_DSP/Source/CommonTables/arm_mve_tables_f16.o ./ARM_DSP/Source/CommonTables/arm_mve_tables_f16.su

.PHONY: clean-ARM_DSP-2f-Source-2f-CommonTables

