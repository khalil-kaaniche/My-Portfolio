/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include "i2c-lcd.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NS  256
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int  prescalers[16]={1491,1407,1328,1254,1183,1117,1054,995,939,886,837,790,745,703,664,627};// for 256 Samples

uint8_t NoteStat[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8_t NoteOn=0x90;
uint8_t NoteOff=0x80;

uint8_t Note[17]={0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48};

uint8_t NoteChromInit[17]={0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48};

uint8_t NoteOrgInit[17]={0x39,0x3B,0x3C,0x3E,0x40,0x41,0x43,0x45,0x47,0x48,0x4A,0x4C,0x4D,0x4F,0x51,0x53};

uint8_t NoteChrom[17]={0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48};

uint8_t NoteOrg[17]={0x39,0x3B,0x3C,0x3E,0x40,0x41,0x43,0x45,0x47,0x48,0x4A,0x4C,0x4D,0x4F,0x51,0x53};

uint8_t NoteVelocity=0x64;

static const uint32_t waveforms[5][NS] =
{
		{		2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,
				2048}, // Zeros
		{		2048, 2098, 2148, 2199, 2249, 2299, 2349, 2399, 2448, 2498, 2547, 2596, 2644, 2692, 2740,
				2787, 2834, 2880, 2926, 2971, 3016, 3060, 3104, 3147, 3189, 3230, 3271, 3311, 3351, 3389,
				3427, 3464, 3500, 3535, 3569, 3602, 3635, 3666, 3697, 3726, 3754, 3782, 3808, 3833, 3857,
				3880, 3902, 3923, 3943, 3961, 3979, 3995, 4010, 4024, 4036, 4048, 4058, 4067, 4074, 4081,
				4086, 4090, 4093, 4095, 4095, 4094, 4092, 4088, 4084, 4078, 4071, 4062, 4053, 4042, 4030,
				4017, 4002, 3987, 3970, 3952, 3933, 3913, 3891, 3869, 3845, 3821, 3795, 3768, 3740, 3711,
				3681, 3651, 3619, 3586, 3552, 3517, 3482, 3445, 3408, 3370, 3331, 3291, 3251, 3210, 3168,
				3125, 3082, 3038, 2994, 2949, 2903, 2857, 2811, 2764, 2716, 2668, 2620, 2571, 2522, 2473,
				2424, 2374, 2324, 2274, 2224, 2174, 2123, 2073, 2022, 1972, 1921, 1871, 1821, 1771, 1721,
				1671, 1622, 1573, 1524, 1475, 1427, 1379, 1331, 1284, 1238, 1192, 1146, 1101, 1057, 1013,
				970, 927, 885, 844, 804, 764, 725, 687, 650, 613, 578, 543, 509, 476, 444,
				414, 384, 355, 327, 300, 274, 250, 226, 204, 182, 162, 143, 125, 108, 93,
				78, 65, 53, 42, 33, 24, 17, 11, 7, 3, 1, 0, 0, 2, 5,
				9, 14, 21, 28, 37, 47, 59, 71, 85, 100, 116, 134, 152, 172, 193,
				215, 238, 262, 287, 313, 341, 369, 398, 429, 460, 493, 526, 560, 595, 631,
				668, 706, 744, 784, 824, 865, 906, 948, 991, 1035, 1079, 1124, 1169, 1215, 1261,
				1308, 1355, 1403, 1451, 1499, 1548, 1597, 1647, 1696, 1746, 1796, 1846, 1896, 1947, 1997,
				2047},// Sine Wave
		{4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
				4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0},// Square
				{0, 32, 64, 96, 128, 161, 193, 225, 257, 289, 321, 353, 385, 418, 450,
						482, 514, 546, 578, 610, 642, 674, 707, 739, 771, 803, 835, 867, 899, 931,
						964, 996, 1028, 1060, 1092, 1124, 1156, 1188, 1220, 1253, 1285, 1317, 1349, 1381, 1413,
						1445, 1477, 1510, 1542, 1574, 1606, 1638, 1670, 1702, 1734, 1766, 1799, 1831, 1863, 1895,
						1927, 1959, 1991, 2023, 2056, 2088, 2120, 2152, 2184, 2216, 2248, 2280, 2312, 2345, 2377,
						2409, 2441, 2473, 2505, 2537, 2569, 2602, 2634, 2666, 2698, 2730, 2762, 2794, 2826, 2858,
						2891, 2923, 2955, 2987, 3019, 3051, 3083, 3115, 3148, 3180, 3212, 3244, 3276, 3308, 3340,
						3372, 3404, 3437, 3469, 3501, 3533, 3565, 3597, 3629, 3661, 3694, 3726, 3758, 3790, 3822,
						3854, 3886, 3918, 3950, 3983, 4015, 4047, 4079, 4079, 4047, 4015, 3983, 3950, 3918, 3886,
						3854, 3822, 3790, 3758, 3726, 3694, 3661, 3629, 3597, 3565, 3533, 3501, 3469, 3437, 3404,
						3372, 3340, 3308, 3276, 3244, 3212, 3180, 3148, 3115, 3083, 3051, 3019, 2987, 2955, 2923,
						2891, 2858, 2826, 2794, 2762, 2730, 2698, 2666, 2634, 2602, 2569, 2537, 2505, 2473, 2441,
						2409, 2377, 2345, 2312, 2280, 2248, 2216, 2184, 2152, 2120, 2088, 2056, 2023, 1991, 1959,
						1927, 1895, 1863, 1831, 1799, 1766, 1734, 1702, 1670, 1638, 1606, 1574, 1542, 1510, 1477,
						1445, 1413, 1381, 1349, 1317, 1285, 1253, 1220, 1188, 1156, 1124, 1092, 1060, 1028, 996,
						964, 931, 899, 867, 835, 803, 771, 739, 707, 674, 642, 610, 578, 546, 514,
						482, 450, 418, 385, 353, 321, 289, 257, 225, 193, 161, 128, 96, 64, 32,
						0},// Triangle
						{0, 16, 32, 48, 64, 80, 96, 112, 128, 145, 161, 177, 193, 209, 225,
								241, 257, 273, 289, 305, 321, 337, 353, 369, 385, 401, 418, 434, 450, 466,
								482, 498, 514, 530, 546, 562, 578, 594, 610, 626, 642, 658, 674, 691, 707,
								723, 739, 755, 771, 787, 803, 819, 835, 851, 867, 883, 899, 915, 931, 947,
								964, 980, 996, 1012, 1028, 1044, 1060, 1076, 1092, 1108, 1124, 1140, 1156, 1172, 1188,
								1204, 1220, 1237, 1253, 1269, 1285, 1301, 1317, 1333, 1349, 1365, 1381, 1397, 1413, 1429,
								1445, 1461, 1477, 1493, 1510, 1526, 1542, 1558, 1574, 1590, 1606, 1622, 1638, 1654, 1670,
								1686, 1702, 1718, 1734, 1750, 1766, 1783, 1799, 1815, 1831, 1847, 1863, 1879, 1895, 1911,
								1927, 1943, 1959, 1975, 1991, 2007, 2023, 2039, 2056, 2072, 2088, 2104, 2120, 2136, 2152,
								2168, 2184, 2200, 2216, 2232, 2248, 2264, 2280, 2296, 2312, 2329, 2345, 2361, 2377, 2393,
								2409, 2425, 2441, 2457, 2473, 2489, 2505, 2521, 2537, 2553, 2569, 2585, 2602, 2618, 2634,
								2650, 2666, 2682, 2698, 2714, 2730, 2746, 2762, 2778, 2794, 2810, 2826, 2842, 2858, 2875,
								2891, 2907, 2923, 2939, 2955, 2971, 2987, 3003, 3019, 3035, 3051, 3067, 3083, 3099, 3115,
								3131, 3148, 3164, 3180, 3196, 3212, 3228, 3244, 3260, 3276, 3292, 3308, 3324, 3340, 3356,
								3372, 3388, 3404, 3421, 3437, 3453, 3469, 3485, 3501, 3517, 3533, 3549, 3565, 3581, 3597,
								3613, 3629, 3645, 3661, 3677, 3694, 3710, 3726, 3742, 3758, 3774, 3790, 3806, 3822, 3838,
								3854, 3870, 3886, 3902, 3918, 3934, 3950, 3967, 3983, 3999, 4015, 4031, 4047, 4063, 4079,
								0}// Sawtooth
};

uint32_t Resultat[NS];

uint32_t Res;

float Coef=0;

uint32_t ResAtt[8192]={0};
uint32_t ResDec[8192]={0};
uint32_t ResSus[NS]={0};
uint32_t ResRel[8192]={0};

uint32_t interm;
uint32_t durA,durD,durR;
static uint16_t adc1 [2] ={30,30};
static uint16_t adc2 [2] ={30,30};
static uint16_t adc3 [2] ={30,30};
float v1=0;
float v2=0;
float v3=0;
float coef=0;
uint16_t btdroite = 0;
uint16_t btgauche = 0;
uint16_t bt1 = 1;
uint16_t bt2 = 1;
uint16_t bt3 = 1;
int i=0;
int j=0;
int valeur=36;
char val[3];
int Octave=0;
int OctavePred=0;
char Octaves[3];
int Tonique=0;
int ToniquePred=0;
char Toniques[3];
uint8_t mode =0;
uint8_t synth =0;
int k=0;
int kpred=0;
float  A=1,D=100,R=100;
float S=0.1;
float Spred=0;
uint8_t MidiMode=0;
uint32_t start=0;
uint32_t timeA,timeD,timeR;

#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000)

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */


/** @brief  Clears the UART NE pending flag.
  * @param  None
  * @retval None
  */
void play(void);


/** @brief  Oscilatos configuration main function.
  * @param  None
  * @retval None
  */
void osc(void);


/** @brief  Change the note buffers by increasing or decreasing an octave for the synth mode.
  * @param  None
  * @retval None
  */
void Octv(void);


/** @brief  Envelope configuration main function
  * @param  None
  * @retval None
  */
void env(void);


/** @brief  MIDI Keyboard main function
  * @param  None
  * @retval None
  */
void midi(void);


/** @brief  Send the midi on note.
  * @param  i (int) : containing the index of the note to play
  * @retval None
  */
void MidiOn(int i);


/** @brief  Send the midi off note.
  * @param  i (int) : containing the index of the note to shut
  * @retval None
  */
void MidiOff(int i);


/** @brief  Change the note buffers by increasing or decreasing an octave for the MIDI mode.
  * @param  None
  * @retval None
  */
void OctaveMidi(void);

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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  MX_DAC_Init();
  MX_TIM2_Init();
  MX_I2C1_Init();
  MX_UART4_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */

  // Welcome Screen
  lcd_init();
  lcd_clear();
  lcd_put_cur(0,0);
  lcd_send_string(&"   Synth V0.4   ");
  HAL_Delay(2000);
  HAL_ADC_Start_DMA(&hadc1,(uint32_t*) adc1, 32);
  adc1[1]=adc1[0];
  HAL_ADC_Start_DMA(&hadc2,(uint32_t*) adc2, 32);
  adc2[1]=adc2[0];
  HAL_ADC_Start_DMA(&hadc3,(uint32_t*) adc3, 32);
  adc3[1]=adc3[0];


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  if(mode==0)
	  {
		  lcd_clear();
		  lcd_put_cur(0, 0);
		  lcd_send_string(&"BG : MIDI Mode");
		  lcd_put_cur(1,0);
		  lcd_send_string(&"BD : SYNTH Mode");
		  while((HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET)){}
		  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
		  {
			  while(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}
			  mode=1;
		  }
		  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port,BDroite_Pin)==GPIO_PIN_SET)
		  {
			  while(HAL_GPIO_ReadPin(BDroite_GPIO_Port,BDroite_Pin)==GPIO_PIN_SET){}
			  mode=2;
		  }
	  }
	  else if(mode==1)
	  {
		  lcd_clear();
		  if(MidiMode==0)
		  {
			  lcd_put_cur(0, 0);
			  lcd_send_string(&"Octave:");
			  lcd_put_cur(1,0);
			  itoa(Octave,Octaves,10);
			  lcd_send_string(&Octaves);
			  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)
			  {
				  while((BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET){}
				  OctavePred=Octave;
				  Octave++;
				  if (Octave>OctavePred)
				  {
					  for(int i=0;i<17;i++)
					  {
					 	NoteChrom[i]=NoteChrom[i]+12;
					 	NoteOrg[i]=NoteOrg[i]+12;
					  }
				  }
			  }
			  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}
				  OctavePred=Octave;
				  Octave--;
				  if (Octave<OctavePred)
				  {
					  for(int i=0;i<17;i++)
					  {
					 	NoteChrom[i]=NoteChrom[i]-12;
					 	NoteOrg[i]=NoteOrg[i]-12;
					  }
				  }
			  }
		  }
		  else if(MidiMode==1)
		  {
			  lcd_put_cur(0, 0);
			  lcd_send_string(&"Mode Chr");
			  lcd_put_cur(1, 0);
			  if(Tonique>=0)
			  {
				  switch(Tonique%12)
				  {
				  case 0:lcd_send_string(&"A");break;
				  case 1:lcd_send_string(&"A#");break;
				  case 2:lcd_send_string(&"B");break;
				  case 3:lcd_send_string(&"C");break;
				  case 4:lcd_send_string(&"C#");break;
				  case 5:lcd_send_string(&"D");break;
				  case 6:lcd_send_string(&"D#");break;
				  case 7:lcd_send_string(&"E");break;
				  case 8:lcd_send_string(&"F");break;
				  case 9:lcd_send_string(&"F#");break;
				  case 10:lcd_send_string(&"G");break;
				  case 11:lcd_send_string(&"G#");break;
				  }
			  }
			  else
			  {
				  switch((11-Tonique)%12)
				  {
				  case 0:lcd_send_string(&"A");break;
				  case 1:lcd_send_string(&"A#");break;
				  case 2:lcd_send_string(&"B");break;
				  case 3:lcd_send_string(&"C");break;
				  case 4:lcd_send_string(&"C#");break;
				  case 5:lcd_send_string(&"D");break;
				  case 6:lcd_send_string(&"D#");break;
				  case 7:lcd_send_string(&"E");break;
				  case 8:lcd_send_string(&"F");break;
				  case 9:lcd_send_string(&"F#");break;
				  case 10:lcd_send_string(&"G");break;
				  case 11:lcd_send_string(&"G#");break;
				  }
			  }
			  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)
			  {
				  while((BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET){}
				  ToniquePred=Tonique;
				  Tonique++;
				  if (Tonique>ToniquePred)
				  {
					  for(int i=0;i<17;i++)
					  {
					 	NoteChrom[i]=NoteChrom[i]+1;
					  }
				  }
			  }

			  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}
				  ToniquePred=Tonique;
				  Tonique--;
				  if (Tonique<ToniquePred)
				  {
					  for(int i=0;i<17;i++)
					  {
					 	NoteChrom[i]=NoteChrom[i]-1;
					  }
				  }
			  }

			  for(int i=0;i<17;i++)
			  {
				  Note[i]=NoteChrom[i];
			  }

		  }
		  else if(MidiMode==2)
		  {
			  lcd_put_cur(0, 0);
			  lcd_send_string(&"Mode Major/Minor");
			  lcd_put_cur(1, 0);
			  if(Tonique>=0)
			  {
				  switch(Tonique%12)
				  {
				  case 0:lcd_send_string(&"A min / C Maj");break;
				  case 1:lcd_send_string(&"A# min / C# Maj");break;
				  case 2:lcd_send_string(&"B min / D Maj");break;
				  case 3:lcd_send_string(&"C min / D# Maj");break;
				  case 4:lcd_send_string(&"C# min / E Maj");break;
				  case 5:lcd_send_string(&"D min / F Maj");break;
				  case 6:lcd_send_string(&"D# min / F# Maj");break;
				  case 7:lcd_send_string(&"E min / G Maj");break;
				  case 8:lcd_send_string(&"F min / G# Maj");break;
				  case 9:lcd_send_string(&"F# min / A Maj");break;
				  case 10:lcd_send_string(&"G min / A# Maj");break;
				  case 11:lcd_send_string(&"G# min / B Maj");break;
				  }
			  }
			  else
			  {
				  switch((11-Tonique)%12)
				  {
				  case 0:lcd_send_string(&"A min / C Maj");break;
				  case 1:lcd_send_string(&"A# min / C# Maj");break;
				  case 2:lcd_send_string(&"B min / D Maj");break;
				  case 3:lcd_send_string(&"C min / D# Maj");break;
				  case 4:lcd_send_string(&"C# min / E Maj");break;
				  case 5:lcd_send_string(&"D min / F Maj");break;
				  case 6:lcd_send_string(&"D# min / F# Maj");break;
				  case 7:lcd_send_string(&"E min / G Maj");break;
				  case 8:lcd_send_string(&"F min / G# Maj");break;
				  case 9:lcd_send_string(&"F# min / A Maj");break;
				  case 10:lcd_send_string(&"G min / A# Maj");break;
				  case 11:lcd_send_string(&"G# min / B Maj");break;
				  }
			  }
			  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)
			  {
				  while((BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET){}
				  ToniquePred=Tonique;
				  Tonique++;
				  if (Tonique>ToniquePred)
				  {
					  for(int i=0;i<17;i++)
					  {
					 	NoteOrg[i]=NoteOrg[i]+1;
					  }
				  }
			  }

			  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}
				  ToniquePred=Tonique;
				  Tonique--;
				  if (Tonique<ToniquePred)
				  {
					  for(int i=0;i<17;i++)
					  {
					 	NoteOrg[i]=NoteOrg[i]-1;
					  }
				  }
			  }

			  for(int i=0;i<17;i++)
			  {
				  Note[i]=NoteOrg[i];
			  }
		  }
		  while((HAL_GPIO_ReadPin(BNon_GPIO_Port, BNon_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOsc1_GPIO_Port,BOsc1_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOsc2_GPIO_Port,BOsc2_Pin)==GPIO_PIN_RESET)&&((HAL_GPIO_ReadPin(BOsc3_GPIO_Port,BOsc3_Pin)==GPIO_PIN_RESET))&&(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET))
		  {
			  midi();
		  }
		  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
		  {
			  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
			  mode=0;
		  }
		  if(HAL_GPIO_ReadPin(BOsc1_GPIO_Port,BOsc1_Pin)==GPIO_PIN_SET)
		  {
			  while(HAL_GPIO_ReadPin(BOsc1_GPIO_Port,BOsc1_Pin)==GPIO_PIN_SET){}
			  MidiMode=0;
		  }
		  else if(HAL_GPIO_ReadPin(BOsc2_GPIO_Port,BOsc2_Pin)==GPIO_PIN_SET)
		  {
			  while(HAL_GPIO_ReadPin(BOsc2_GPIO_Port,BOsc2_Pin)==GPIO_PIN_SET){}
			  MidiMode=1;
		  }
		  else if(HAL_GPIO_ReadPin(BOsc3_GPIO_Port,BOsc3_Pin)==GPIO_PIN_SET)
		  {
			  while(HAL_GPIO_ReadPin(BOsc3_GPIO_Port,BOsc3_Pin)==GPIO_PIN_SET){}
			  MidiMode=2;
		  }
	  }
	  else if(mode==2)
	  {
		  if(synth==0)
		  {
			  lcd_clear();
			  lcd_put_cur(0, 0);
			  lcd_send_string(&"BG: OSCs BD:Octv");
			  lcd_put_cur(1,0);
			  lcd_send_string(&"BO:Play BOs1:Env");
			  while((HAL_GPIO_ReadPin(BNon_GPIO_Port, BNon_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOsc1_GPIO_Port,BOsc1_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_RESET)){}
			  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
				  mode=0;
			  }
			  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}
				  synth=1;
			  }
			  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port,BDroite_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BDroite_GPIO_Port,BDroite_Pin)==GPIO_PIN_SET){}
				  synth=2;
			  }
			  if(HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_SET){}
				  synth=3;
			  }
			if(HAL_GPIO_ReadPin(BOsc1_GPIO_Port,BOsc1_Pin)==GPIO_PIN_SET)
			  {
				while(HAL_GPIO_ReadPin(BOsc1_GPIO_Port,BOsc1_Pin)==GPIO_PIN_SET){}
				synth=4;
			  }
		  }
		  while(synth==1)
		  {
			  osc();
			  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
				  synth=0;
			  }
		  }
		  while(synth==2)
		  {
			  Octv();
		  }
		  while(synth==3)
		  {
			  play();
			  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
				  synth=0;
			  }
		  }
		  while(synth==4)
		  {
			  env();
			  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
			  {
				  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
				  synth=0;
			  }
		  }
	  }
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void MidiOn(int i)
{
	  HAL_UART_Transmit_IT(&huart4, &NoteOn, sizeof(NoteOn));
	  while(HAL_UART_GetState(&huart4)!=HAL_UART_STATE_READY){}
	  HAL_UART_Transmit_IT(&huart4, &Note[i], sizeof(Note[i]));
	  while(HAL_UART_GetState(&huart4)!=HAL_UART_STATE_READY){}
	  HAL_UART_Transmit_IT(&huart4, &NoteVelocity, sizeof(NoteVelocity));
	  while(HAL_UART_GetState(&huart4)!=HAL_UART_STATE_READY){}
	  NoteStat[i]=1;
}
void MidiOff(int i)
{
	  HAL_UART_Transmit_IT(&huart4, &NoteOff, sizeof(NoteOff));
	  while(HAL_UART_GetState(&huart4)!=HAL_UART_STATE_READY){}
	  HAL_UART_Transmit_IT(&huart4, &Note[i], sizeof(Note[i]));
	  while(HAL_UART_GetState(&huart4)!=HAL_UART_STATE_READY){}
	  HAL_UART_Transmit_IT(&huart4, &NoteVelocity, sizeof(NoteVelocity));
	  while(HAL_UART_GetState(&huart4)!=HAL_UART_STATE_READY){}
	  NoteStat[i]=0;
}
void OctaveMidi(void)
{
	  lcd_clear();
	  lcd_put_cur(0, 0);
	  lcd_send_string(&"Octave:");
	  lcd_put_cur(1,0);
	  itoa(Octave,Octaves,10);
	  lcd_send_string(&Octaves);
	  while((HAL_GPIO_ReadPin(BNon_GPIO_Port, BNon_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET)){}
	  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
	  {
		  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
		  MidiMode=0;
	  }
	  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)
	  {
		  while((HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)){}
		  OctavePred=Octave;
		  Octave++;
		  if(Octave>OctavePred)
		  {
			  for (int i=0;i<17;i++)
			  {
				  NoteChrom[i]=NoteChrom[i]+12;
				  NoteOrg[i]=NoteOrg[i]+12;
			  }
		  }
	  }
	  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
	  {
		  while((HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)){}
		  OctavePred=Octave;
		  Octave--;
		  if(Octave<OctavePred)
		  {
			  for (int i=0;i<17;i++)
			  {
				  NoteChrom[i]=NoteChrom[i]-12;
				  NoteOrg[i]=NoteOrg[i]-12;
			  }
		  }
	  }
}
void midi(void)
{
	  if((HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_SET)&&(NoteStat[0]==0))
	  {
		  MidiOn(0);
	  }
	  if((HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_RESET)&&(NoteStat[0]==1))
	  {
		  MidiOff(0);
	  }
	  if((HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_SET)&&(NoteStat[1]==0))
	  {
		  MidiOn(1);
	  }
	  if((HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_RESET)&&(NoteStat[1]==1))
	  {
		  MidiOff(1);
	  }
	  if((HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)==GPIO_PIN_SET)&&(NoteStat[2]==0))
	  {
		  MidiOn(2);
	  }
	  if((HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)==GPIO_PIN_RESET)&&(NoteStat[2]==1))
	  {
		  MidiOff(2);
	  }
	  if((HAL_GPIO_ReadPin(B4_GPIO_Port, B4_Pin)==GPIO_PIN_SET)&&(NoteStat[3]==0))
	  {
		  MidiOn(3);
	  }
	  if((HAL_GPIO_ReadPin(B4_GPIO_Port, B4_Pin)==GPIO_PIN_RESET)&&(NoteStat[3]==1))
	  {
		  MidiOff(3);
	  }
	  if((HAL_GPIO_ReadPin(B5_GPIO_Port, B5_Pin)==GPIO_PIN_SET)&&(NoteStat[4]==0))
	  {
		  MidiOn(4);
	  }
	  if((HAL_GPIO_ReadPin(B5_GPIO_Port, B5_Pin)==GPIO_PIN_RESET)&&(NoteStat[4]==1))
	  {
		  MidiOff(4);
	  }

	  if((HAL_GPIO_ReadPin(B6_GPIO_Port, B6_Pin)==GPIO_PIN_SET)&&(NoteStat[5]==0))
	  {
		  MidiOn(5);
	  }
	  if((HAL_GPIO_ReadPin(B6_GPIO_Port, B6_Pin)==GPIO_PIN_RESET)&&(NoteStat[5]==1))
	  {
		  MidiOff(5);
	  }

	  if((HAL_GPIO_ReadPin(B7_GPIO_Port, B7_Pin)==GPIO_PIN_SET)&&(NoteStat[6]==0))
	  {
		  MidiOn(6);
	  }
	  if((HAL_GPIO_ReadPin(B7_GPIO_Port, B7_Pin)==GPIO_PIN_RESET)&&(NoteStat[6]==1))
	  {
		  MidiOff(6);
	  }

	  if((HAL_GPIO_ReadPin(B8_GPIO_Port, B8_Pin)==GPIO_PIN_SET)&&(NoteStat[7]==0))
	  {
		  MidiOn(7);
	  }
	  if((HAL_GPIO_ReadPin(B8_GPIO_Port, B8_Pin)==GPIO_PIN_RESET)&&(NoteStat[7]==1))
	  {
		  MidiOff(7);
	  }

	  if((HAL_GPIO_ReadPin(B9_GPIO_Port, B9_Pin)==GPIO_PIN_SET)&&(NoteStat[8]==0))
	  {
		  MidiOn(8);
	  }
	  if((HAL_GPIO_ReadPin(B9_GPIO_Port, B9_Pin)==GPIO_PIN_RESET)&&(NoteStat[8]==1))
	  {
		  MidiOff(8);
	  }

	  if((HAL_GPIO_ReadPin(B10_GPIO_Port, B10_Pin)==GPIO_PIN_SET)&&(NoteStat[9]==0))
	  {
		  MidiOn(9);
	  }
	  if((HAL_GPIO_ReadPin(B10_GPIO_Port, B10_Pin)==GPIO_PIN_RESET)&&(NoteStat[9]==1))
	  {
		  MidiOff(9);
	  }
	  if((HAL_GPIO_ReadPin(B11_GPIO_Port, B11_Pin)==GPIO_PIN_SET)&&(NoteStat[10]==0))
	  {
		  MidiOn(10);
	  }
	  if((HAL_GPIO_ReadPin(B11_GPIO_Port, B11_Pin)==GPIO_PIN_RESET)&&(NoteStat[10]==1))
	  {
		  MidiOff(10);
	  }

	  if((HAL_GPIO_ReadPin(B12_GPIO_Port, B12_Pin)==GPIO_PIN_SET)&&(NoteStat[11]==0))
	  {
		  MidiOn(11);
	  }
	  if((HAL_GPIO_ReadPin(B12_GPIO_Port, B12_Pin)==GPIO_PIN_RESET)&&(NoteStat[11]==1))
	  {
		  MidiOff(11);
	  }

	  if((HAL_GPIO_ReadPin(B13_GPIO_Port, B13_Pin)==GPIO_PIN_SET)&&(NoteStat[12]==0))
	  {
		  MidiOn(12);
	  }
	  if((HAL_GPIO_ReadPin(B13_GPIO_Port, B13_Pin)==GPIO_PIN_RESET)&&(NoteStat[12]==1))
	  {
		  MidiOff(12);
	  }

	  if((HAL_GPIO_ReadPin(B14_GPIO_Port, B14_Pin)==GPIO_PIN_SET)&&(NoteStat[13]==0))
	  {
		  MidiOn(13);
	  }
	  if((HAL_GPIO_ReadPin(B14_GPIO_Port, B14_Pin)==GPIO_PIN_RESET)&&(NoteStat[13]==1))
	  {
		  MidiOff(13);
	  }

	  if((HAL_GPIO_ReadPin(B15_GPIO_Port, B15_Pin)==GPIO_PIN_SET)&&(NoteStat[14]==0))
	  {
		  MidiOn(14);
	  }
	  if((HAL_GPIO_ReadPin(B15_GPIO_Port, B15_Pin)==GPIO_PIN_RESET)&&(NoteStat[14]==1))
	  {
		  MidiOff(14);
	  }

	  if((HAL_GPIO_ReadPin(B16_GPIO_Port, B16_Pin)==GPIO_PIN_SET)&&(NoteStat[15]==0))
	  {
		  MidiOn(15);
	  }
	  if((HAL_GPIO_ReadPin(B16_GPIO_Port, B16_Pin)==GPIO_PIN_RESET)&&(NoteStat[15]==1))
	  {
		  MidiOff(15);
	  }
}
void play(void)
{
	  lcd_init();
	  lcd_clear();
	  lcd_put_cur(0,0);
	  lcd_send_string(&"   Enjoy   ");
	  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_RESET)
	  {
		    HAL_TIM_Base_Stop(&htim2);
		    HAL_TIM_Base_DeInit(&htim2);
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		  //Note 1
		  if((HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_SET)&&(NoteStat[0]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[0]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[0]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_RESET)&&(NoteStat[0]==1))
		  {

			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[0]=0;
		  }
		 // Note 2
		  if((HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_SET)&&(NoteStat[1]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[1]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[1]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_RESET)&&(NoteStat[1]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[1]=0;
		  }
		  // Note 3
		  if((HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)==GPIO_PIN_SET)&&(NoteStat[2]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[2]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[2]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)==GPIO_PIN_RESET)&&(NoteStat[2]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[2]=0;
		  }
		  // Note 4

		  if((HAL_GPIO_ReadPin(B4_GPIO_Port, B4_Pin)==GPIO_PIN_SET)&&(NoteStat[3]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[3]);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B4_GPIO_Port, B4_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[3]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B4_GPIO_Port, B4_Pin)==GPIO_PIN_RESET)&&(NoteStat[3]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[3]=0;
		  }

		  // Note 5
		  if((HAL_GPIO_ReadPin(B5_GPIO_Port, B5_Pin)==GPIO_PIN_SET)&&(NoteStat[4]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[4]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B5_GPIO_Port, B5_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[4]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B5_GPIO_Port, B5_Pin)==GPIO_PIN_RESET)&&(NoteStat[4]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[4]=0;
		  }

		  // Note 6
		  if((HAL_GPIO_ReadPin(B6_GPIO_Port, B6_Pin)==GPIO_PIN_SET)&&(NoteStat[5]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[5]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B6_GPIO_Port, B6_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[5]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B6_GPIO_Port, B6_Pin)==GPIO_PIN_RESET)&&(NoteStat[5]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[5]=0;
		  }

		  // Note 7
		  if((HAL_GPIO_ReadPin(B7_GPIO_Port, B7_Pin)==GPIO_PIN_SET)&&(NoteStat[6]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[6]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B7_GPIO_Port, B7_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[6]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B7_GPIO_Port, B7_Pin)==GPIO_PIN_RESET)&&(NoteStat[6]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[6]=0;
		  }

		  // Note 8
		  if((HAL_GPIO_ReadPin(B8_GPIO_Port, B8_Pin)==GPIO_PIN_SET)&&(NoteStat[7]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[7]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B8_GPIO_Port, B8_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[7]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B8_GPIO_Port, B8_Pin)==GPIO_PIN_RESET)&&(NoteStat[7]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[7]=0;
		  }

		  // Note 9
		  if((HAL_GPIO_ReadPin(B9_GPIO_Port, B9_Pin)==GPIO_PIN_SET)&&(NoteStat[8]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[8]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B9_GPIO_Port, B9_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[8]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B9_GPIO_Port, B9_Pin)==GPIO_PIN_RESET)&&(NoteStat[8]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[8]=0;
		  }

		  // Note 10
		  if((HAL_GPIO_ReadPin(B10_GPIO_Port, B10_Pin)==GPIO_PIN_SET)&&(NoteStat[9]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[9]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B10_GPIO_Port, B10_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[9]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B10_GPIO_Port, B10_Pin)==GPIO_PIN_RESET)&&(NoteStat[9]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[9]=0;
		  }

		  //Note 11

		  if((HAL_GPIO_ReadPin(B11_GPIO_Port, B11_Pin)==GPIO_PIN_SET)&&(NoteStat[10]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[10]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B11_GPIO_Port, B11_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[10]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B11_GPIO_Port, B11_Pin)==GPIO_PIN_RESET)&&(NoteStat[10]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[10]=0;
		  }

		  //Note 12
		  if((HAL_GPIO_ReadPin(B12_GPIO_Port, B12_Pin)==GPIO_PIN_SET)&&(NoteStat[11]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[11]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B12_GPIO_Port, B12_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[11]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B12_GPIO_Port, B12_Pin)==GPIO_PIN_RESET)&&(NoteStat[11]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[11]=0;
		  }

		  // Note 13
		  if((HAL_GPIO_ReadPin(B13_GPIO_Port, B13_Pin)==GPIO_PIN_SET)&&(NoteStat[12]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[12]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B13_GPIO_Port, B13_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[12]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B13_GPIO_Port, B13_Pin)==GPIO_PIN_RESET)&&(NoteStat[12]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[12]=0;
		  }

		  //Note 14
		  if((HAL_GPIO_ReadPin(B14_GPIO_Port, B14_Pin)==GPIO_PIN_SET)&&(NoteStat[13]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[13]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B14_GPIO_Port, B14_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[13]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B14_GPIO_Port, B14_Pin)==GPIO_PIN_RESET)&&(NoteStat[13]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[13]=0;
		  }

		  // Note 15
		  if((HAL_GPIO_ReadPin(B15_GPIO_Port, B15_Pin)==GPIO_PIN_SET)&&(NoteStat[14]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[14]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B15_GPIO_Port, B15_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[14]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B15_GPIO_Port, B15_Pin)==GPIO_PIN_RESET)&&(NoteStat[14]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[14]=0;
		  }

		  // Note 16
		  if((HAL_GPIO_ReadPin(B16_GPIO_Port, B16_Pin)==GPIO_PIN_SET)&&(NoteStat[15]==0))
		  {
			    HAL_TIM_Base_DeInit(&htim2);
			  	TIM2_Init(prescalers[15]);

			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResAtt,durA, DAC_ALIGN_12B_R);
			    HAL_TIM_Base_Start(&htim2);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResDec,durD, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				while(HAL_GPIO_ReadPin(B16_GPIO_Port, B16_Pin)==GPIO_PIN_SET)
				{
			    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResSus,256, DAC_ALIGN_12B_R);
			    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
			    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
				}
				NoteStat[15]=1;
		  }
		  if ((HAL_GPIO_ReadPin(B16_GPIO_Port, B16_Pin)==GPIO_PIN_RESET)&&(NoteStat[15]==1))
		  {
			HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)ResRel,durR, DAC_ALIGN_12B_R);
		    while(HAL_DAC_GetState(&hdac)!=HAL_DAC_STATE_READY){}
		    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		    NoteStat[15]=0;
		  }
	  }

}
void Octv(void)
{
	  lcd_clear();
	  lcd_put_cur(0, 0);
	  lcd_send_string(&"Octave:");
	  lcd_put_cur(1,0);
	  itoa(k,val,10);
	  lcd_send_string(&val);

	  while((HAL_GPIO_ReadPin(BNon_GPIO_Port, BNon_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET)){}
	  if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
	  {
		  while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
		  synth=0;
	  }
	  if(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)
	  {
		while((BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET){}
			kpred=k;
			k++;
			  if(k>kpred)
			  {
				for (int i =0;i<16;i++)
				{
					prescalers[i]=prescalers[i]/2;
				}
			  }
	  }
	  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
	  {
		while((BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}

			kpred=k;
			k--;
			  if(k<kpred)
			  {
				for (int i =0;i<16;i++)
				{
					prescalers[i]=prescalers[i]*2;
				}
			  }

	  }
}
void osc(void)
{
	  lcd_clear();
	  lcd_put_cur(0, 0);
	  itoa(bt1,val,10);
	  lcd_send_string(&val);
	  lcd_put_cur(0, 5);
	  itoa(bt2,val,10);
	  lcd_send_string(&val);
	  lcd_put_cur(0, 10);
	  itoa(bt3,val,10);
	  lcd_send_string(&val);

	  lcd_put_cur(1, 0);
	  itoa(adc1[0],val,10);
	  lcd_send_string(&val);
	  lcd_put_cur(1, 5);
	  itoa(adc2[0],val,10);
	  lcd_send_string(&val);
	  lcd_put_cur(1, 10);
	  itoa(adc3[0],val,10);
	  lcd_send_string(&val);
	  for(int i=0 ; i<256;i++)
	  	  {
		  long int test1=((adc1[0]+1))*0.33*(waveforms[bt1][i]/64);
		  long int test2=((adc2[0]+1))*0.33*(waveforms[bt2][i]/64);
		  long int test3=((adc3[0]+1))*0.33*(waveforms[bt3][i]/64);
		  float testfloat = (0.33*(adc1[0]+adc2[0]+adc3[0]+3)/64);
		  testfloat=2048*(1-testfloat);
		  Resultat[i]=test1+test2+test3+testfloat;
	  	  }
		while((HAL_GPIO_ReadPin(BOsc1_GPIO_Port, BOsc1_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOsc2_GPIO_Port, BOsc2_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOsc3_GPIO_Port, BOsc3_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET)){}
		if(HAL_GPIO_ReadPin(BOsc1_GPIO_Port, BOsc1_Pin)==GPIO_PIN_SET)
		{
			while(HAL_GPIO_ReadPin(BOsc1_GPIO_Port, BOsc1_Pin)==GPIO_PIN_SET){}
			bt1=(bt1+1)%5;
		}
		if(HAL_GPIO_ReadPin(BOsc2_GPIO_Port, BOsc2_Pin)==GPIO_PIN_SET)
		{
			while(HAL_GPIO_ReadPin(BOsc2_GPIO_Port, BOsc2_Pin)==GPIO_PIN_SET){}
			bt2=(bt2+1)%5;
		}
		if(HAL_GPIO_ReadPin(BOsc3_GPIO_Port, BOsc3_Pin)==GPIO_PIN_SET)
		{
			while(HAL_GPIO_ReadPin(BOsc3_GPIO_Port, BOsc3_Pin)==GPIO_PIN_SET){}
			bt3=(bt3+1)%5;
		}
		if(HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_SET)
		{
			while(HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_SET){}
			synth=0;
		}
		HAL_ADC_Stop_DMA(&hadc1);
		HAL_ADC_Stop_DMA(&hadc2);
		HAL_ADC_Stop_DMA(&hadc3);
		HAL_ADC_Start_DMA(&hadc1,(uint32_t*) adc1, 32);
		HAL_ADC_Start_DMA(&hadc2,(uint32_t*) adc2, 32);
		HAL_ADC_Start_DMA(&hadc3,(uint32_t*) adc3, 32);
}
void env(void)
{

	  HAL_ADC_Stop_DMA(&hadc1);
	  HAL_ADC_Stop_DMA(&hadc2);
	  HAL_ADC_Stop_DMA(&hadc3);
	  HAL_ADC_Start_DMA(&hadc1,(uint32_t*) adc1, 32);
	  HAL_ADC_Start_DMA(&hadc2,(uint32_t*) adc2, 32);
	  HAL_ADC_Start_DMA(&hadc3,(uint32_t*) adc3, 32);
	// de 1 à 64 les valeurs de l'adc (résolution 6 bit )
	  A=(adc1[0]+0);
	  D=(adc2[0]+1);
	  R=(adc3[0]+0);
	  durA=32*A*4;
	  durD=32*D*4;
	  durR=32*R*4;
	  //Prendre les valeurs de A,D et R;


	  lcd_clear();
	  lcd_put_cur(0, 0);
	  lcd_send_string(&"A:");
	  lcd_put_cur(0, 8);
	  lcd_send_string(&"D:");

	  lcd_put_cur(1, 0);
	  lcd_send_string(&"S:");
	  lcd_put_cur(1,5);
	  lcd_send_string(&"/10 ");
	  lcd_put_cur(1, 8);
	  lcd_send_string(&"R:");

	  lcd_put_cur(0, 3);
	  itoa(A,val,10);
	  lcd_send_string(&val);
	  lcd_put_cur(0, 11);
	  itoa(D,val,10);
	  lcd_send_string(&val);

	  lcd_put_cur(1, 3);
	  itoa(10*S,val,10);
	  lcd_send_string(&val);
	  lcd_put_cur(1, 11);
	  itoa(R,val,10);
	  lcd_send_string(&val);
	  // Affichage des valeurs
	  A=32*A*4;
	  D=32*D*4;
	  R=32*R*4;

	  // traitement ADSR
	  HAL_FLASH_Unlock();
	  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
	  FLASH_Erase_Sector(FLASH_SECTOR_3, VOLTAGE_RANGE_3);
	  // Tabs de Res
	  for (int i=0;i<A;i++)
	  {
		  coef=(i/A)*Resultat[i%256];
		  float testfloat=(1-(i/A))*2048;
		  interm=coef+testfloat;
		  //ResAtt[i]=coef+testfloat;
		  HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, ResAtt+i, interm);
	  }
	  for(int i=0;i<D;i++)
	  {
		  coef=((((S-1)/D)*i)+1)*Resultat[(i+durA)%256];
		  float testfloat=(1-((((S-1)/D)*i)+1))*2048;
		  //ResDec[i]=coef+testfloat;
		  interm=coef+testfloat;
		  HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ResDec+i, interm);
	  }
	  ;
	  for(int i=0;i<256;i++)
	  {
		  coef=S*Resultat[(i+durA+durD)%256];
		  float testfloat=(1-S)*2048;
		  //ResSus[i]=coef+testfloat;
		  interm=coef+testfloat;
		  HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ResSus+i, interm);
	  }
	  for(int i=0;i<R;i++)
	  {
		  coef=((-S/R)*i+S)*Resultat[(i+durA+durD+256)%256];
		  float testfloat=(1-((-S/R)*i+S))*2048;
		  //ResRel[i]=coef+testfloat;
		  interm=coef+testfloat;
		  HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, ResRel+i, interm);
	  }

	  //Commandes pour revenir dans le menu ;
	  //Boutton gauche et droite pour faire varier Sustain
		while((HAL_GPIO_ReadPin(BOui_GPIO_Port,BOui_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BDroite_GPIO_Port,BDroite_Pin)==GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_RESET)){}
		if(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET)
		{
			while(HAL_GPIO_ReadPin(BNon_GPIO_Port,BNon_Pin)==GPIO_PIN_SET){}
			synth=0;
		}
		if(HAL_GPIO_ReadPin(BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET)
			  {
				while((BDroite_GPIO_Port, BDroite_Pin)==GPIO_PIN_SET){}
					if(S>=1){S=1;}
					else
					{
						Spred=S;
						S=S+0.1;
					}
			  }
			  if(HAL_GPIO_ReadPin(BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET)
			  {
				while((BGauche_GPIO_Port,BGauche_Pin)==GPIO_PIN_SET){}
					if(S<=0.1){S=0.1;}
					else
					{
						Spred=S;
						S=S-0.1;
					}

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
