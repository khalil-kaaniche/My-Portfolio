/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MAX30102.h"
#include "MyDsp.h"
#include "arm_math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#ifndef HSEM_ID_0
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
#endif
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

#define SamplingFrequencyHz			1000
#define SYSORD						4
#define SYSORD2						4
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
uint32_t RED=0;
uint32_t IR=0;

uint32_t SampleTaken = 0 ;
double Data = 0 ;

double HR1 = 0 ;
double HR2 = 0 ;

extern double Frequence;
extern double Maxim;
extern double Minim;

extern double Frequence2;
extern double Maxim2;
extern double Minim2;

extern double Spo2;


IIR_Filter LpFilter;
Circular_Buffer LpFilterInputBuffer;
Circular_Buffer LpFilterOutputBuffer;
double LpFilterOutput =0;

IIR_Filter LpFilter2;
Circular_Buffer LpFilterInputBuffer2;
Circular_Buffer LpFilterOutputBuffer2;
double LpFilterOutput2 =0;


IIR_Filter HpFilter;
Circular_Buffer HpFilterInputBuffer;
Circular_Buffer HpFilterOutputBuffer;
double HpFilterOutput =0;

IIR_Filter HpFilter2;
Circular_Buffer HpFilterInputBuffer2;
Circular_Buffer HpFilterOutputBuffer2;
double HpFilterOutput2 =0;





double CoeffNum[SYSORD] = {1.036668483278547e-07,3.110005449835640e-07,3.110005449835640e-07,1.036668483278547e-07};
double CoeffDenum[SYSORD] = {1 , -2.981150513836762,2.962478260680657,-0.981326917509109};

double CoeffNum2[SYSORD2] = {0.996863335697075,-2.990590007091225,2.990590007091225,-0.996863335697075};
double CoeffDenum2[SYSORD2] = {1,-2.993716817276653,2.987453358242848,-0.993736510057099};

double ContainerRED[1000]={0};
double ContainerIR[1000]={0};

double MaxRed=0;
double MaxIR=0;
double MinRed=0;
double MinIR=0;
double R = 0 ;

double Spo2v2 = 0 ;

double HeartRateFinal = 0 ;
double Spo2Final = 0 ;

char Buf[50];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_I2C1_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

  CircBuff_Init(&LpFilterInputBuffer, SYSORD);
  CircBuff_Init(&LpFilterOutputBuffer, SYSORD);
  IIR_Init(&LpFilter, SYSORD, &CoeffNum[0], SYSORD, &CoeffDenum[0]);

  CircBuff_Init(&LpFilterInputBuffer2, SYSORD);
  CircBuff_Init(&LpFilterOutputBuffer2, SYSORD);
  IIR_Init(&LpFilter2, SYSORD, &CoeffNum[0], SYSORD, &CoeffDenum[0]);

  CircBuff_Init(&HpFilterInputBuffer, SYSORD2);
  CircBuff_Init(&HpFilterOutputBuffer, SYSORD2);
  IIR_Init(&HpFilter, SYSORD2, &CoeffNum2[0], SYSORD2, &CoeffDenum2[0]);

  CircBuff_Init(&HpFilterInputBuffer2, SYSORD2);
  CircBuff_Init(&HpFilterOutputBuffer2, SYSORD2);
  IIR_Init(&HpFilter2, SYSORD2, &CoeffNum2[0], SYSORD2, &CoeffDenum2[0]);

  MAX30102_Init();

  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x307075B1;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 240000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

// Raw Data Acquisition
	MAX30102_GetValues(&RED, &IR) ;

// IR Data filter
	Data = IR ;

	CircBuff_Write(&LpFilterInputBuffer, Data);
	LpFilterOutput = IIR_Calculate(&LpFilter, &LpFilterInputBuffer, &LpFilterOutputBuffer);
	CircBuff_Write(&LpFilterOutputBuffer, LpFilterOutput);

	CircBuff_Write(&HpFilterInputBuffer, LpFilterOutput);
	HpFilterOutput = IIR_Calculate(&HpFilter, &HpFilterInputBuffer, &HpFilterOutputBuffer);
	CircBuff_Write(&HpFilterOutputBuffer, HpFilterOutput);

	DSP_ExtremumV3(HpFilterOutput, &Maxim, &Minim, &Frequence);

// RED Data filter
	Data = RED ;
	CircBuff_Write(&LpFilterInputBuffer2, Data);
	LpFilterOutput2 = IIR_Calculate(&LpFilter2, &LpFilterInputBuffer2, &LpFilterOutputBuffer2);
	CircBuff_Write(&LpFilterOutputBuffer2, LpFilterOutput2);

	CircBuff_Write(&HpFilterInputBuffer2, LpFilterOutput2);
	HpFilterOutput2 = IIR_Calculate(&HpFilter2, &HpFilterInputBuffer2, &HpFilterOutputBuffer2);
	CircBuff_Write(&HpFilterOutputBuffer2, HpFilterOutput2);

	DSP_ExtremumV4(HpFilterOutput2, &Maxim2, &Minim2, &Frequence2);

// Collect the calculated Heart rate frequencies
	HR1 = Frequence;
	HR2 = Frequence2;

	ContainerIR[SampleTaken] = IR;
	ContainerRED[SampleTaken] = RED;
	SampleTaken++;

// Data collection done
	if(SampleTaken==1000)
	{
		arm_max_no_idx_f64(ContainerRED, 1000, &MaxRed);
		arm_max_no_idx_f64(ContainerIR, 1000, &MaxIR);
		arm_min_no_idx_f64(ContainerRED, 1000, &MinRed);
		arm_min_no_idx_f64(ContainerIR, 1000, &MinIR);
		R = (MaxRed/MinRed)/(MaxIR/MinIR);
		// We are using two different approximations for Spo2 calculation and Heart rate
		Spo2 = -16.5191 * (R*R) - 7.9276 * R + 124.4951;
		Spo2v2 = 125 - 25 * R;
		Spo2Final = 0.5*(Spo2 + Spo2v2);
		HeartRateFinal =( HR1 + HR2 )*0.5;
		SampleTaken = 0;
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
