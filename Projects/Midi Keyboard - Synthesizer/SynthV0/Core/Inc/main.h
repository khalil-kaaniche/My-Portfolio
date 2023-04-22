/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B4_Pin GPIO_PIN_2
#define B4_GPIO_Port GPIOE
#define B3_Pin GPIO_PIN_3
#define B3_GPIO_Port GPIOE
#define B2_Pin GPIO_PIN_4
#define B2_GPIO_Port GPIOE
#define B1_Pin GPIO_PIN_5
#define B1_GPIO_Port GPIOE
#define Osc2_Pin GPIO_PIN_1
#define Osc2_GPIO_Port GPIOA
#define Osc3_Pin GPIO_PIN_2
#define Osc3_GPIO_Port GPIOA
#define BOsc1_Pin GPIO_PIN_7
#define BOsc1_GPIO_Port GPIOE
#define BOsc2_Pin GPIO_PIN_8
#define BOsc2_GPIO_Port GPIOE
#define BOsc3_Pin GPIO_PIN_9
#define BOsc3_GPIO_Port GPIOE
#define BGauche_Pin GPIO_PIN_10
#define BGauche_GPIO_Port GPIOE
#define BDroite_Pin GPIO_PIN_11
#define BDroite_GPIO_Port GPIOE
#define BOui_Pin GPIO_PIN_12
#define BOui_GPIO_Port GPIOE
#define BNon_Pin GPIO_PIN_13
#define BNon_GPIO_Port GPIOE
#define LD4_GreenLed_Pin GPIO_PIN_12
#define LD4_GreenLed_GPIO_Port GPIOD
#define LD3_OrangeLed_Pin GPIO_PIN_13
#define LD3_OrangeLed_GPIO_Port GPIOD
#define LD5_RedLed_Pin GPIO_PIN_14
#define LD5_RedLed_GPIO_Port GPIOD
#define LD6_BlueLed_Pin GPIO_PIN_15
#define LD6_BlueLed_GPIO_Port GPIOD
#define B8_Pin GPIO_PIN_1
#define B8_GPIO_Port GPIOD
#define B14_Pin GPIO_PIN_2
#define B14_GPIO_Port GPIOD
#define B16_Pin GPIO_PIN_3
#define B16_GPIO_Port GPIOD
#define B15_Pin GPIO_PIN_4
#define B15_GPIO_Port GPIOD
#define B13_Pin GPIO_PIN_6
#define B13_GPIO_Port GPIOD
#define B12_Pin GPIO_PIN_7
#define B12_GPIO_Port GPIOD
#define B11_Pin GPIO_PIN_3
#define B11_GPIO_Port GPIOB
#define B10_Pin GPIO_PIN_4
#define B10_GPIO_Port GPIOB
#define B9_Pin GPIO_PIN_5
#define B9_GPIO_Port GPIOB
#define B7_Pin GPIO_PIN_7
#define B7_GPIO_Port GPIOB
#define B6_Pin GPIO_PIN_0
#define B6_GPIO_Port GPIOE
#define B5_Pin GPIO_PIN_1
#define B5_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
