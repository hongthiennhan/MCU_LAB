/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#include "traffic_light.h"

/*
  This file normalizes LED handling so each logical LED (VLED/HLED)
  drives two physical pins: <NAME>1 and <NAME>2.
  It also removes any direct operations on the old LED7 pin.
*/

/* --- Helper macros to write/toggle both copies of each LED --- */
/* VLED (vertical) */
#define VLED_RED_WRITE(state)    do { HAL_GPIO_WritePin(VLED_RED1_GPIO_Port,    VLED_RED1_Pin,    state); HAL_GPIO_WritePin(VLED_RED2_GPIO_Port,    VLED_RED2_Pin,    state); } while(0)
#define VLED_YELLOW_WRITE(state) do { HAL_GPIO_WritePin(VLED_YELLOW1_GPIO_Port, VLED_YELLOW1_Pin, state); HAL_GPIO_WritePin(VLED_YELLOW2_GPIO_Port, VLED_YELLOW2_Pin, state); } while(0)
#define VLED_GREEN_WRITE(state)  do { HAL_GPIO_WritePin(VLED_GREEN1_GPIO_Port,  VLED_GREEN1_Pin,  state); HAL_GPIO_WritePin(VLED_GREEN2_GPIO_Port,  VLED_GREEN2_Pin,  state); } while(0)

#define VLED_RED_TOGGLE()    do { HAL_GPIO_TogglePin(VLED_RED1_GPIO_Port,    VLED_RED1_Pin);    HAL_GPIO_TogglePin(VLED_RED2_GPIO_Port,    VLED_RED2_Pin);    } while(0)
#define VLED_YELLOW_TOGGLE() do { HAL_GPIO_TogglePin(VLED_YELLOW1_GPIO_Port, VLED_YELLOW1_Pin); HAL_GPIO_TogglePin(VLED_YELLOW2_GPIO_Port, VLED_YELLOW2_Pin); } while(0)
#define VLED_GREEN_TOGGLE()  do { HAL_GPIO_TogglePin(VLED_GREEN1_GPIO_Port,  VLED_GREEN1_Pin);  HAL_GPIO_TogglePin(VLED_GREEN2_GPIO_Port,  VLED_GREEN2_Pin);  } while(0)

/* HLED (horizontal) */
#define HLED_RED_WRITE(state)    do { HAL_GPIO_WritePin(HLED_RED1_GPIO_Port,    HLED_RED1_Pin,    state); HAL_GPIO_WritePin(HLED_RED2_GPIO_Port,    HLED_RED2_Pin,    state); } while(0)
#define HLED_YELLOW_WRITE(state) do { HAL_GPIO_WritePin(HLED_YELLOW1_GPIO_Port, HLED_YELLOW1_Pin, state); HAL_GPIO_WritePin(HLED_YELLOW2_GPIO_Port, HLED_YELLOW2_Pin, state); } while(0)
#define HLED_GREEN_WRITE(state)  do { HAL_GPIO_WritePin(HLED_GREEN1_GPIO_Port,  HLED_GREEN1_Pin,  state); HAL_GPIO_WritePin(HLED_GREEN2_GPIO_Port,  HLED_GREEN2_Pin,  state); } while(0)

#define HLED_RED_TOGGLE()    do { HAL_GPIO_TogglePin(HLED_RED1_GPIO_Port,    HLED_RED1_Pin);    HAL_GPIO_TogglePin(HLED_RED2_GPIO_Port,    HLED_RED2_Pin);    } while(0)
#define HLED_YELLOW_TOGGLE() do { HAL_GPIO_TogglePin(HLED_YELLOW1_GPIO_Port, HLED_YELLOW1_Pin); HAL_GPIO_TogglePin(HLED_YELLOW2_GPIO_Port, HLED_YELLOW2_Pin); } while(0)
#define HLED_GREEN_TOGGLE()  do { HAL_GPIO_TogglePin(HLED_GREEN1_GPIO_Port,  HLED_GREEN1_Pin);  HAL_GPIO_TogglePin(HLED_GREEN2_GPIO_Port,  HLED_GREEN2_Pin);  } while(0)

/* --- Traffic timings (kept here for convenience) --- */
int redTime = 5;
int yellowTime = 2;
int greenTime = 3;

/* --- Traffic state output functions --- */
void trafficGreenRed(void) {
    VLED_RED_WRITE(GPIO_PIN_RESET);
    VLED_YELLOW_WRITE(GPIO_PIN_RESET);
    VLED_GREEN_WRITE(GPIO_PIN_SET);

    HLED_RED_WRITE(GPIO_PIN_SET);
    HLED_YELLOW_WRITE(GPIO_PIN_RESET);
    HLED_GREEN_WRITE(GPIO_PIN_RESET);
}

void trafficYellowRed(void) {
    VLED_RED_WRITE(GPIO_PIN_RESET);
    VLED_YELLOW_WRITE(GPIO_PIN_SET);
    VLED_GREEN_WRITE(GPIO_PIN_RESET);

    HLED_RED_WRITE(GPIO_PIN_SET);
    HLED_YELLOW_WRITE(GPIO_PIN_RESET);
    HLED_GREEN_WRITE(GPIO_PIN_RESET);
}

void trafficRedGreen(void) {
    VLED_RED_WRITE(GPIO_PIN_SET);
    VLED_YELLOW_WRITE(GPIO_PIN_RESET);
    VLED_GREEN_WRITE(GPIO_PIN_RESET);

    HLED_RED_WRITE(GPIO_PIN_RESET);
    HLED_YELLOW_WRITE(GPIO_PIN_RESET);
    HLED_GREEN_WRITE(GPIO_PIN_SET);
}

void trafficRedYellow(void) {
    VLED_RED_WRITE(GPIO_PIN_SET);
    VLED_YELLOW_WRITE(GPIO_PIN_RESET);
    VLED_GREEN_WRITE(GPIO_PIN_RESET);

    HLED_RED_WRITE(GPIO_PIN_RESET);
    HLED_YELLOW_WRITE(GPIO_PIN_SET);
    HLED_GREEN_WRITE(GPIO_PIN_RESET);
}

/* --- Update / adjust time helper functions --- */
void updateRedTime(void) {
    if (redTime < 99) {
        redTime++;
    }
}
void updateGreenTime(void) {
    if (greenTime < 99) {
        greenTime++;
    }
}
void updateYellowTime(void) {
    if (yellowTime < 99) {
        yellowTime++;
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

/* --- Clear / blink helpers.
   NOTE: these functions operate on both physical copies (1 & 2). ---
*/
void clearTrafficLight(void) {
    VLED_RED_WRITE(GPIO_PIN_RESET);
    VLED_YELLOW_WRITE(GPIO_PIN_RESET);
    VLED_GREEN_WRITE(GPIO_PIN_RESET);

    HLED_RED_WRITE(GPIO_PIN_RESET);
    HLED_YELLOW_WRITE(GPIO_PIN_RESET);
    HLED_GREEN_WRITE(GPIO_PIN_RESET);
}

void blinkRedLed(void) {
    VLED_RED_TOGGLE();
    HLED_RED_TOGGLE();
    VLED_YELLOW_WRITE(GPIO_PIN_RESET);
    VLED_GREEN_WRITE(GPIO_PIN_RESET);
    HLED_YELLOW_WRITE(GPIO_PIN_RESET);
    HLED_GREEN_WRITE(GPIO_PIN_RESET);
}

void blinkYellowLed(void) {
    VLED_YELLOW_TOGGLE();
    HLED_YELLOW_TOGGLE();
    VLED_RED_WRITE(GPIO_PIN_RESET);
    VLED_GREEN_WRITE(GPIO_PIN_RESET);
    HLED_RED_WRITE(GPIO_PIN_RESET);
    HLED_GREEN_WRITE(GPIO_PIN_RESET);
}

void blinkGreenLed(void) {
    VLED_GREEN_TOGGLE();
    HLED_GREEN_TOGGLE();
    VLED_RED_WRITE(GPIO_PIN_RESET);
    VLED_YELLOW_WRITE(GPIO_PIN_RESET);
    HLED_RED_WRITE(GPIO_PIN_RESET);
    HLED_YELLOW_WRITE(GPIO_PIN_RESET);
}

void blinkAllLed(void) {
    VLED_RED_TOGGLE();
    HLED_RED_TOGGLE();
    VLED_YELLOW_TOGGLE();
    HLED_YELLOW_TOGGLE();
    VLED_GREEN_TOGGLE();
    HLED_GREEN_TOGGLE();
}
