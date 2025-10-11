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
#define LED_MATRIX_ROW5_Pin GPIO_PIN_13
#define LED_MATRIX_ROW5_GPIO_Port GPIOC
#define LED_MATRIX_ROW6_Pin GPIO_PIN_14
#define LED_MATRIX_ROW6_GPIO_Port GPIOC
#define LED_MATRIX_ROW7_Pin GPIO_PIN_15
#define LED_MATRIX_ROW7_GPIO_Port GPIOC
#define LED_7SEG_C_Pin GPIO_PIN_4
#define LED_7SEG_C_GPIO_Port GPIOA
#define LED_MATRIX_ROW0_Pin GPIO_PIN_5
#define LED_MATRIX_ROW0_GPIO_Port GPIOA
#define LED_7SEG1_CTRL_Pin GPIO_PIN_6
#define LED_7SEG1_CTRL_GPIO_Port GPIOA
#define LED_7SEG2_CTRL_Pin GPIO_PIN_7
#define LED_7SEG2_CTRL_GPIO_Port GPIOA
#define LED_7SEG_A_Pin GPIO_PIN_0
#define LED_7SEG_A_GPIO_Port GPIOB
#define LED_7SEG_B_Pin GPIO_PIN_1
#define LED_7SEG_B_GPIO_Port GPIOB
#define LED_MATRIX_COL2_Pin GPIO_PIN_10
#define LED_MATRIX_COL2_GPIO_Port GPIOB
#define LED_MATRIX_COL3_Pin GPIO_PIN_11
#define LED_MATRIX_COL3_GPIO_Port GPIOB
#define LED_MATRIX_COL4_Pin GPIO_PIN_12
#define LED_MATRIX_COL4_GPIO_Port GPIOB
#define LED_MATRIX_COL5_Pin GPIO_PIN_13
#define LED_MATRIX_COL5_GPIO_Port GPIOB
#define LED_MATRIX_COL6_Pin GPIO_PIN_14
#define LED_MATRIX_COL6_GPIO_Port GPIOB
#define LED_MATRIX_COL7_Pin GPIO_PIN_15
#define LED_MATRIX_COL7_GPIO_Port GPIOB
#define LED_DOT1_Pin GPIO_PIN_9
#define LED_DOT1_GPIO_Port GPIOC
#define LED_7SEG3_CTRL_Pin GPIO_PIN_8
#define LED_7SEG3_CTRL_GPIO_Port GPIOA
#define LED_7SEG4_CTRL_Pin GPIO_PIN_9
#define LED_7SEG4_CTRL_GPIO_Port GPIOA
#define LED_MATRIX_ROW1_Pin GPIO_PIN_10
#define LED_MATRIX_ROW1_GPIO_Port GPIOA
#define LED_MATRIX_ROW2_Pin GPIO_PIN_11
#define LED_MATRIX_ROW2_GPIO_Port GPIOA
#define LED_MATRIX_ROW3_Pin GPIO_PIN_12
#define LED_MATRIX_ROW3_GPIO_Port GPIOA
#define LED_MATRIX_ROW4_Pin GPIO_PIN_15
#define LED_MATRIX_ROW4_GPIO_Port GPIOA
#define LED_DOT2_Pin GPIO_PIN_10
#define LED_DOT2_GPIO_Port GPIOC
#define LED_7SEG_D_Pin GPIO_PIN_4
#define LED_7SEG_D_GPIO_Port GPIOB
#define LED_7SEG_E_Pin GPIO_PIN_5
#define LED_7SEG_E_GPIO_Port GPIOB
#define LED_7SEG_F_Pin GPIO_PIN_6
#define LED_7SEG_F_GPIO_Port GPIOB
#define LED_7SEG_G_Pin GPIO_PIN_7
#define LED_7SEG_G_GPIO_Port GPIOB
#define LED_MATRIX_COL0_Pin GPIO_PIN_8
#define LED_MATRIX_COL0_GPIO_Port GPIOB
#define LED_MATRIX_COL1_Pin GPIO_PIN_9
#define LED_MATRIX_COL1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
