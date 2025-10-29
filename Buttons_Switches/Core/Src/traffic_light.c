/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#include "traffic_light.h"

int redTime = 5;
int yellowTime = 2;
int greenTime = 3;

void trafficGreenRed() {
    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_RESET);
}
void trafficYellowRed() {
    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_RESET);
}
void trafficRedGreen() {
    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_SET);
}
void trafficRedYellow() {
    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_RESET);
}

void updateRedTime() {
    if (redTime < 99) {
        redTime++;
        greenTime++;
    }
}
void updateGreenTime() {
    if (redTime < 99) {
        greenTime++;
        redTime++;
    }
}
void updateYellowTime() {
    if (redTime < 99 && yellowTime < greenTime) {
        yellowTime++;
        redTime++;
    }
}

void setRedTime(int redValue) {
    redTime = redValue;
}
void setYellowTime(int yellowValue) {
    yellowTime = yellowValue;
}
void setGreenTime(int greenValue) {
    greenTime = greenValue;
}

void clearTrafficLight() {
    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_RESET);
}

void blinkRedLed() {
    HAL_GPIO_TogglePin(VLED_RED_GPIO_Port, VLED_RED_Pin);
    HAL_GPIO_TogglePin(HLED_RED_GPIO_Port, HLED_RED_Pin);
    HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);

    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_RESET);
}
void blinkYellowLed() {
    HAL_GPIO_TogglePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin);
    HAL_GPIO_TogglePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin);
    HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);

    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin, GPIO_PIN_RESET);
}
void blinkGreenLed() {
    HAL_GPIO_TogglePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin);
    HAL_GPIO_TogglePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin);
    HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);

    HAL_GPIO_WritePin(VLED_RED_GPIO_Port, VLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_RED_GPIO_Port, HLED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin, GPIO_PIN_RESET);
}

void blinkAllLed() {
    HAL_GPIO_TogglePin(VLED_RED_GPIO_Port, VLED_RED_Pin);
    HAL_GPIO_TogglePin(HLED_RED_GPIO_Port, HLED_RED_Pin);
    HAL_GPIO_TogglePin(VLED_YELLOW_GPIO_Port, VLED_YELLOW_Pin);
    HAL_GPIO_TogglePin(HLED_YELLOW_GPIO_Port, HLED_YELLOW_Pin);
    HAL_GPIO_TogglePin(VLED_GREEN_GPIO_Port, VLED_GREEN_Pin);
    HAL_GPIO_TogglePin(HLED_GREEN_GPIO_Port, HLED_GREEN_Pin);
    HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);
}
