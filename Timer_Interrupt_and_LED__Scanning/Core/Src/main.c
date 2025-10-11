/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define MAX_LED 4
uint8_t ledBuffer[MAX_LED] = {1, 2, 3, 4};
uint8_t ledIndex = 0;

volatile uint16_t timer0_counter = 0;
volatile uint8_t timer0_flag = 0;
volatile uint16_t timer1_counter = 0;
volatile uint8_t timer1_flag = 0;
uint16_t TIMER_CYCLE = 1;

void setTimer0(uint16_t duration) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimer1(uint16_t duration) {
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

void timer_run() {
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter == 0) timer0_flag = 1;
	}

	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter == 0) timer1_flag = 1;
	}
}

void display7SEG(uint8_t num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 0);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 0);
			break;
    
		default:
			HAL_GPIO_WritePin(LED_7SEG_A_GPIO_Port, LED_7SEG_A_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_B_GPIO_Port, LED_7SEG_B_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_C_GPIO_Port, LED_7SEG_C_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_D_GPIO_Port, LED_7SEG_D_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_E_GPIO_Port, LED_7SEG_E_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_F_GPIO_Port, LED_7SEG_F_Pin, 1);
			HAL_GPIO_WritePin(LED_7SEG_G_GPIO_Port, LED_7SEG_G_Pin, 1);
			break;
	}
}

void update7SEG(uint8_t index) {
  switch (index) {
    case 0: 
      HAL_GPIO_WritePin(LED_7SEG1_CTRL_GPIO_Port, LED_7SEG1_CTRL_Pin, 0);
      HAL_GPIO_WritePin(LED_7SEG2_CTRL_GPIO_Port, LED_7SEG2_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG3_CTRL_GPIO_Port, LED_7SEG3_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG4_CTRL_GPIO_Port, LED_7SEG4_CTRL_Pin, 1);
      display7SEG(ledBuffer[0]);
      break;
    case 1:
      HAL_GPIO_WritePin(LED_7SEG1_CTRL_GPIO_Port, LED_7SEG1_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG2_CTRL_GPIO_Port, LED_7SEG2_CTRL_Pin, 0);
      HAL_GPIO_WritePin(LED_7SEG3_CTRL_GPIO_Port, LED_7SEG3_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG4_CTRL_GPIO_Port, LED_7SEG4_CTRL_Pin, 1);
      display7SEG(ledBuffer[1]);
      break;
    case 2:
      HAL_GPIO_WritePin(LED_7SEG1_CTRL_GPIO_Port, LED_7SEG1_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG2_CTRL_GPIO_Port, LED_7SEG2_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG3_CTRL_GPIO_Port, LED_7SEG3_CTRL_Pin, 0);
      HAL_GPIO_WritePin(LED_7SEG4_CTRL_GPIO_Port, LED_7SEG4_CTRL_Pin, 1);
      display7SEG(ledBuffer[2]);
      break;
    case 3:
      HAL_GPIO_WritePin(LED_7SEG1_CTRL_GPIO_Port, LED_7SEG1_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG2_CTRL_GPIO_Port, LED_7SEG2_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG3_CTRL_GPIO_Port, LED_7SEG3_CTRL_Pin, 1);
      HAL_GPIO_WritePin(LED_7SEG4_CTRL_GPIO_Port, LED_7SEG4_CTRL_Pin, 0);
      display7SEG(ledBuffer[3]);
      break;
    default:
      break;
  }
}

void updateClockBuffer(uint8_t hour, uint8_t minute, uint8_t second) {
  ledBuffer[0] = hour / 10;
  ledBuffer[1] = hour % 10;
  ledBuffer[2] = minute / 10;
  ledBuffer[3] = minute % 10;
}

#define MAX_LED_MATRIX 8
uint8_t index_led_matrix = 0;
uint8_t matrix_buffer[MAX_LED_MATRIX] = {
    0b00111100,
    0b01100110,
    0b11000011,
    0b11000011,
    0b11111111,
    0b11000011,
    0b11000011,
    0b11000011
};

void setColumn(uint8_t data) {
    HAL_GPIO_WritePin(LED_MATRIX_COL0_GPIO_Port, LED_MATRIX_COL0_Pin, (data & 0x01) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL1_GPIO_Port, LED_MATRIX_COL1_Pin, (data & 0x02) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL2_GPIO_Port, LED_MATRIX_COL2_Pin, (data & 0x04) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL3_GPIO_Port, LED_MATRIX_COL3_Pin, (data & 0x08) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL4_GPIO_Port, LED_MATRIX_COL4_Pin, (data & 0x10) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL5_GPIO_Port, LED_MATRIX_COL5_Pin, (data & 0x20) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL6_GPIO_Port, LED_MATRIX_COL6_Pin, (data & 0x40) ? 1 : 0);
    HAL_GPIO_WritePin(LED_MATRIX_COL7_GPIO_Port, LED_MATRIX_COL7_Pin, (data & 0x80) ? 1 : 0);
}

void clearAllRows(void) {
    HAL_GPIO_WritePin(LED_MATRIX_ROW0_GPIO_Port, LED_MATRIX_ROW0_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW1_GPIO_Port, LED_MATRIX_ROW1_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW2_GPIO_Port, LED_MATRIX_ROW2_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW3_GPIO_Port, LED_MATRIX_ROW3_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW4_GPIO_Port, LED_MATRIX_ROW4_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW5_GPIO_Port, LED_MATRIX_ROW5_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW6_GPIO_Port, LED_MATRIX_ROW6_Pin, 0);
    HAL_GPIO_WritePin(LED_MATRIX_ROW7_GPIO_Port, LED_MATRIX_ROW7_Pin, 0);
}

void updateLEDMatrix(uint8_t index) {
	  clearAllRows();
	  switch (index) {
	    case 0:
	      setColumn(matrix_buffer[0]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW0_GPIO_Port, LED_MATRIX_ROW0_Pin, 1);
	      break;
	    case 1:
	      setColumn(matrix_buffer[1]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW1_GPIO_Port, LED_MATRIX_ROW1_Pin, 1);
	      break;
	    case 2:
	      setColumn(matrix_buffer[2]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW2_GPIO_Port, LED_MATRIX_ROW2_Pin, 1);
	      break;
	    case 3:
	      setColumn(matrix_buffer[3]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW3_GPIO_Port, LED_MATRIX_ROW3_Pin, 1);
	      break;
	    case 4:
	      setColumn(matrix_buffer[4]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW4_GPIO_Port, LED_MATRIX_ROW4_Pin, 1);
	      break;
	    case 5:
	      setColumn(matrix_buffer[5]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW5_GPIO_Port, LED_MATRIX_ROW5_Pin, 1);
	      break;
	    case 6:
	      setColumn(matrix_buffer[6]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW6_GPIO_Port, LED_MATRIX_ROW6_Pin, 1);
	      break;
	    case 7:
	      setColumn(matrix_buffer[7]);
	      HAL_GPIO_WritePin(LED_MATRIX_ROW7_GPIO_Port, LED_MATRIX_ROW7_Pin, 1);
	      break;
	    default:
	      break;
	  }
}

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
  /* USER CODE BEGIN 2 */
  uint8_t hour = 23, minute = 58, second = 10;
  uint8_t ledMaxtrixIndex = 0;
  HAL_TIM_Base_Start_IT(&htim2);
  setTimer0(1);
  setTimer1(1);
  HAL_GPIO_WritePin(LED_7SEG1_CTRL_GPIO_Port, LED_7SEG1_CTRL_Pin, 1);
  HAL_GPIO_WritePin(LED_7SEG2_CTRL_GPIO_Port, LED_7SEG2_CTRL_Pin, 1);
  HAL_GPIO_WritePin(LED_7SEG3_CTRL_GPIO_Port, LED_7SEG3_CTRL_Pin, 1);
  HAL_GPIO_WritePin(LED_7SEG4_CTRL_GPIO_Port, LED_7SEG4_CTRL_Pin, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if (timer0_flag) {
		  updateLEDMatrix(ledMaxtrixIndex);
		  ledMaxtrixIndex = (ledMaxtrixIndex + 1) % MAX_LED_MATRIX;
		  setTimer0(1);
	  }
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  htim2.Init.Prescaler = 799;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_MATRIX_ROW5_Pin|LED_MATRIX_ROW6_Pin|LED_MATRIX_ROW7_Pin|LED_DOT1_Pin
                          |LED_DOT2_Pin, 0);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin|LED_MATRIX_ROW0_Pin|LED_7SEG1_CTRL_Pin|LED_7SEG2_CTRL_Pin
                          |LED_7SEG3_CTRL_Pin|LED_7SEG4_CTRL_Pin|LED_MATRIX_ROW1_Pin|LED_MATRIX_ROW2_Pin
                          |LED_MATRIX_ROW3_Pin|LED_MATRIX_ROW4_Pin, 0);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_7SEG_A_Pin|LED_7SEG_B_Pin|LED_MATRIX_COL2_Pin|LED_MATRIX_COL3_Pin
                          |LED_MATRIX_COL4_Pin|LED_MATRIX_COL5_Pin|LED_MATRIX_COL6_Pin|LED_MATRIX_COL7_Pin
                          |LED_7SEG_D_Pin|LED_7SEG_E_Pin|LED_7SEG_F_Pin|LED_7SEG_G_Pin
                          |LED_MATRIX_COL0_Pin|LED_MATRIX_COL1_Pin, 0);

  /*Configure GPIO pins : LED_MATRIX_ROW5_Pin LED_MATRIX_ROW6_Pin LED_MATRIX_ROW7_Pin LED_DOT1_Pin
                           LED_DOT2_Pin */
  GPIO_InitStruct.Pin = LED_MATRIX_ROW5_Pin|LED_MATRIX_ROW6_Pin|LED_MATRIX_ROW7_Pin|LED_DOT1_Pin
                          |LED_DOT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_7SEG_C_Pin LED_MATRIX_ROW0_Pin LED_7SEG1_CTRL_Pin LED_7SEG2_CTRL_Pin
                           LED_7SEG3_CTRL_Pin LED_7SEG4_CTRL_Pin LED_MATRIX_ROW1_Pin LED_MATRIX_ROW2_Pin
                           LED_MATRIX_ROW3_Pin LED_MATRIX_ROW4_Pin */
  GPIO_InitStruct.Pin = LED_7SEG_C_Pin|LED_MATRIX_ROW0_Pin|LED_7SEG1_CTRL_Pin|LED_7SEG2_CTRL_Pin
                          |LED_7SEG3_CTRL_Pin|LED_7SEG4_CTRL_Pin|LED_MATRIX_ROW1_Pin|LED_MATRIX_ROW2_Pin
                          |LED_MATRIX_ROW3_Pin|LED_MATRIX_ROW4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_7SEG_A_Pin LED_7SEG_B_Pin LED_MATRIX_COL2_Pin LED_MATRIX_COL3_Pin
                           LED_MATRIX_COL4_Pin LED_MATRIX_COL5_Pin LED_MATRIX_COL6_Pin LED_MATRIX_COL7_Pin
                           LED_7SEG_D_Pin LED_7SEG_E_Pin LED_7SEG_F_Pin LED_7SEG_G_Pin
                           LED_MATRIX_COL0_Pin LED_MATRIX_COL1_Pin */
  GPIO_InitStruct.Pin = LED_7SEG_A_Pin|LED_7SEG_B_Pin|LED_MATRIX_COL2_Pin|LED_MATRIX_COL3_Pin
                          |LED_MATRIX_COL4_Pin|LED_MATRIX_COL5_Pin|LED_MATRIX_COL6_Pin|LED_MATRIX_COL7_Pin
                          |LED_7SEG_D_Pin|LED_7SEG_E_Pin|LED_7SEG_F_Pin|LED_7SEG_G_Pin
                          |LED_MATRIX_COL0_Pin|LED_MATRIX_COL1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
volatile uint16_t timer = 1000;
volatile uint8_t counter = 5;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timer_run();

//	timer--;
//	if (timer <= 0) {
//		timer = 1000;
//
//		HAL_GPIO_TogglePin(LED_DOT1_GPIO_Port, LED_DOT1_Pin);
//		HAL_GPIO_TogglePin(LED_DOT2_GPIO_Port, LED_DOT2_Pin);
//	}
//	if (timer0_flag == 1)
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
#ifdef USE_FULL_ASSERT
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
