/*
 * manual.c
 *
 *  Created on: 11 thg 10, 2022
 *      Author: Thiện Nhân
 */

#include "manual.h"
#include "traffic_light.h"   // ensure prototype for turnOnAllLed is visible

void fsm_manual() {
    switch(status) {
        case MAN: {
            updateBufferXLine(mode);
            updateBufferYLine(0);
            /* restore LED7 blinking indicator */
            if (timer_flag[3] == 1) {
                setTimer(3, 500);
                blinkAllLed();
            }
            if (isButtonPressed(0)) {
                status = MODE2;
                mode = 2;
                redValue = redTime;
                yellowValue = yellowTime;
                greenValue = greenTime;
                updateBufferXLine(mode);
                updateBufferYLine(redTime);
                clearTrafficLight();
            }
            break;
        }
        case MODE2: {
            /* restore LED7 blink for MODE2 */
            if (timer_flag[3] == 1) {
                setTimer(3, 500);
                blinkRedLed();
            }
            if (isButtonPressed(0)) {
                status = MODE3;
                mode = 3;
                tempYellow = yellowTime;
                updateBufferXLine(mode);
                updateBufferYLine(tempYellow);
                clearTrafficLight();
                break;
            }
            if (isButtonPressed(1)) {
                if (tempRed < 99) tempRed++;
                else tempRed = 1;
                updateBufferYLine(tempRed);
                break;
            }
            if (isButtonPressed(2)) {
                setRedTime(tempRed);  /* save only on BTN3 */
                turnOnAllLed();       /* new: when BTN3 pressed, light all LEDs */
                break;
            }
            break;
        }
        case MODE3: {
            /* restore LED7 blink for MODE3 */
            if (timer_flag[3] == 1) {
                setTimer(3, 500);
                blinkYellowLed();
            }
            if (isButtonPressed(0)) {
                status = MODE4;
                mode = 4;
                tempGreen = greenTime;
                updateBufferXLine(mode);
                updateBufferYLine(tempGreen);
                clearTrafficLight();
                break;
            }
            if (isButtonPressed(1)) {
                if (tempYellow < 99) tempYellow++;
                else tempYellow = 1;
                updateBufferYLine(tempYellow);
                break;
            }
            if (isButtonPressed(2)) {
                setYellowTime(tempYellow); /* save only on BTN3 */
                turnOnAllLed();            /* new: when BTN3 pressed, light all LEDs */
                break;
            }
            break;
        }
        case MODE4: {
            /* restore LED7 blink for MODE4 */
            if (timer_flag[3] == 1) {
                setTimer(3, 500);
                blinkGreenLed();
            }
            if (isButtonPressed(0)) {
                status = AUTO;
                clearTrafficLight();
                mode = 0;
                break;
            }
            if (isButtonPressed(1)) {
                if (tempGreen < 99) tempGreen++;
                else tempGreen = 1;
                updateBufferYLine(tempGreen);
                break;
            }
            if (isButtonPressed(2)) {
                setGreenTime(tempGreen); /* save only on BTN3 */
                turnOnAllLed();          /* new: when BTN3 pressed, light all LEDs */
                break;
            }
            break;
        }
        default: {
            break;
        }
    }
}
