/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define HLED_RED1_Pin GPIO_PIN_0
#define HLED_RED1_GPIO_Port GPIOC
#define HLED_YELLOW1_Pin GPIO_PIN_1
#define HLED_YELLOW1_GPIO_Port GPIOC
#define HLED_GREEN1_Pin GPIO_PIN_2
#define HLED_GREEN1_GPIO_Port GPIOC
#define VLED_RED1_Pin GPIO_PIN_3
#define VLED_RED1_GPIO_Port GPIOC
#define SEG2_Pin GPIO_PIN_4
#define SEG2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOA
#define VLED_YELLOW1_Pin GPIO_PIN_4
#define VLED_YELLOW1_GPIO_Port GPIOC
#define VLED_GREEN1_Pin GPIO_PIN_5
#define VLED_GREEN1_GPIO_Port GPIOC
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_10
#define BTN3_GPIO_Port GPIOB
#define HLED_RED2_Pin GPIO_PIN_6
#define HLED_RED2_GPIO_Port GPIOC
#define HLED_YELLOW2_Pin GPIO_PIN_7
#define HLED_YELLOW2_GPIO_Port GPIOC
#define HLED_GREEN2_Pin GPIO_PIN_8
#define HLED_GREEN2_GPIO_Port GPIOC
#define VLED_RED2_Pin GPIO_PIN_9
#define VLED_RED2_GPIO_Port GPIOC
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOA
#define VLED_YELLOW2_Pin GPIO_PIN_10
#define VLED_YELLOW2_GPIO_Port GPIOC
#define VLED_GREEN2_Pin GPIO_PIN_11
#define VLED_GREEN2_GPIO_Port GPIOC
#define SEG3_Pin GPIO_PIN_4
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_5
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_6
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_7
#define SEG6_GPIO_Port GPIOB
#define BTN1_Pin GPIO_PIN_8
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_9
#define BTN2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
