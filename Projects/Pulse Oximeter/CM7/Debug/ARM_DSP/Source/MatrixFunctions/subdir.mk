################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ARM_DSP/Source/MatrixFunctions/MatrixFunctionsF16.c \
../ARM_DSP/Source/MatrixFunctions/arm_householder_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_householder_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_householder_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_add_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_add_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_add_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_add_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_init_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_init_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_init_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_init_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_init_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_opt_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q7.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f64.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q7.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f16.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f32.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q15.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q31.c \
../ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q7.c 

OBJS += \
./ARM_DSP/Source/MatrixFunctions/MatrixFunctionsF16.o \
./ARM_DSP/Source/MatrixFunctions/arm_householder_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_householder_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_householder_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_opt_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q7.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f64.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q7.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f16.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f32.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q15.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q31.o \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q7.o 

C_DEPS += \
./ARM_DSP/Source/MatrixFunctions/MatrixFunctionsF16.d \
./ARM_DSP/Source/MatrixFunctions/arm_householder_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_householder_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_householder_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_opt_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q7.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f64.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q7.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f16.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f32.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q15.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q31.d \
./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q7.d 


# Each subdirectory must supply rules for building sources it contributes
ARM_DSP/Source/MatrixFunctions/%.o ARM_DSP/Source/MatrixFunctions/%.su: ../ARM_DSP/Source/MatrixFunctions/%.c ARM_DSP/Source/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM7 -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/Include" -I"C:/Users/khalil/STM32CubeIDE/workspace_1.4.0/Oxy/Test_Oxymetre_3/CM7/ARM_DSP/PrivateInclude" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ARM_DSP-2f-Source-2f-MatrixFunctions

clean-ARM_DSP-2f-Source-2f-MatrixFunctions:
	-$(RM) ./ARM_DSP/Source/MatrixFunctions/MatrixFunctionsF16.d ./ARM_DSP/Source/MatrixFunctions/MatrixFunctionsF16.o ./ARM_DSP/Source/MatrixFunctions/MatrixFunctionsF16.su ./ARM_DSP/Source/MatrixFunctions/arm_householder_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_householder_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_householder_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_householder_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_householder_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_householder_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_householder_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_householder_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_householder_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_add_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cholesky_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_cmplx_trans_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_init_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_inverse_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_ldlt_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_opt_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_opt_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_opt_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q31.d
	-$(RM) ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q7.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q7.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_mult_q7.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_qr_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_scale_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_lower_triangular_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_solve_upper_triangular_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_sub_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f64.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f64.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_f64.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q7.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q7.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_trans_q7.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f16.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f16.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f16.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f32.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f32.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_f32.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q15.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q15.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q15.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q31.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q31.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q31.su ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q7.d ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q7.o ./ARM_DSP/Source/MatrixFunctions/arm_mat_vec_mult_q7.su

.PHONY: clean-ARM_DSP-2f-Source-2f-MatrixFunctions

