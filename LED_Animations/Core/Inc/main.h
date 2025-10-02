/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define MATRIX_ROW6_Pin GPIO_PIN_13
#define MATRIX_ROW6_GPIO_Port GPIOC
#define MATRIX_ROW7_Pin GPIO_PIN_14
#define MATRIX_ROW7_GPIO_Port GPIOC
#define MATRIX_ROW8_Pin GPIO_PIN_15
#define MATRIX_ROW8_GPIO_Port GPIOC
#define LED_9_Pin GPIO_PIN_0
#define LED_9_GPIO_Port GPIOC
#define LED_8_Pin GPIO_PIN_1
#define LED_8_GPIO_Port GPIOC
#define LED_7_Pin GPIO_PIN_2
#define LED_7_GPIO_Port GPIOC
#define LED_6_Pin GPIO_PIN_3
#define LED_6_GPIO_Port GPIOC
#define SEG7_C_Pin GPIO_PIN_4
#define SEG7_C_GPIO_Port GPIOA
#define MATRIX_ROW1_Pin GPIO_PIN_5
#define MATRIX_ROW1_GPIO_Port GPIOA
#define SEG7_CTRL_0_Pin GPIO_PIN_6
#define SEG7_CTRL_0_GPIO_Port GPIOA
#define SEG7_CTRL_1_Pin GPIO_PIN_7
#define SEG7_CTRL_1_GPIO_Port GPIOA
#define LED_5_Pin GPIO_PIN_4
#define LED_5_GPIO_Port GPIOC
#define LED_4_Pin GPIO_PIN_5
#define LED_4_GPIO_Port GPIOC
#define SEG7_A_Pin GPIO_PIN_0
#define SEG7_A_GPIO_Port GPIOB
#define SEG7_B_Pin GPIO_PIN_1
#define SEG7_B_GPIO_Port GPIOB
#define MATRIX_COL3_Pin GPIO_PIN_10
#define MATRIX_COL3_GPIO_Port GPIOB
#define MATRIX_COL4_Pin GPIO_PIN_11
#define MATRIX_COL4_GPIO_Port GPIOB
#define MATRIX_COL5_Pin GPIO_PIN_12
#define MATRIX_COL5_GPIO_Port GPIOB
#define MATRIX_COL6_Pin GPIO_PIN_13
#define MATRIX_COL6_GPIO_Port GPIOB
#define MATRIX_COL7_Pin GPIO_PIN_14
#define MATRIX_COL7_GPIO_Port GPIOB
#define MATRIX_COL8_Pin GPIO_PIN_15
#define MATRIX_COL8_GPIO_Port GPIOB
#define LED_3_Pin GPIO_PIN_6
#define LED_3_GPIO_Port GPIOC
#define LED_2_Pin GPIO_PIN_7
#define LED_2_GPIO_Port GPIOC
#define LED_1_Pin GPIO_PIN_8
#define LED_1_GPIO_Port GPIOC
#define LED_12_Pin GPIO_PIN_9
#define LED_12_GPIO_Port GPIOC
#define SEG7_CTRL_2_Pin GPIO_PIN_8
#define SEG7_CTRL_2_GPIO_Port GPIOA
#define SEG7_CTRL_3_Pin GPIO_PIN_9
#define SEG7_CTRL_3_GPIO_Port GPIOA
#define MATRIX_ROW2_Pin GPIO_PIN_10
#define MATRIX_ROW2_GPIO_Port GPIOA
#define MATRIX_ROW3_Pin GPIO_PIN_11
#define MATRIX_ROW3_GPIO_Port GPIOA
#define MATRIX_ROW4_Pin GPIO_PIN_12
#define MATRIX_ROW4_GPIO_Port GPIOA
#define MATRIX_ROW5_Pin GPIO_PIN_15
#define MATRIX_ROW5_GPIO_Port GPIOA
#define LED_11_Pin GPIO_PIN_10
#define LED_11_GPIO_Port GPIOC
#define LED_10_Pin GPIO_PIN_11
#define LED_10_GPIO_Port GPIOC
#define SEG7_D_Pin GPIO_PIN_4
#define SEG7_D_GPIO_Port GPIOB
#define SEG7_E_Pin GPIO_PIN_5
#define SEG7_E_GPIO_Port GPIOB
#define SEG7_F_Pin GPIO_PIN_6
#define SEG7_F_GPIO_Port GPIOB
#define SEG7_G_Pin GPIO_PIN_7
#define SEG7_G_GPIO_Port GPIOB
#define MATRIX_COL1_Pin GPIO_PIN_8
#define MATRIX_COL1_GPIO_Port GPIOB
#define MATRIX_COL2_Pin GPIO_PIN_9
#define MATRIX_COL2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
