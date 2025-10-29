/*
 * manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#include "manual.h"

void fsm_manual() {
	switch(status) {
		case MAN: {
			updateBufferXLine(mode);
			updateBufferYLine(0);
			if (timer_flag[3] == 1) {
				setTimer(3, 500); // Timer 4
				blinkAllLed(); // Blink 2Hz
			}
			if (isButtonPressed(0)) {
				status = MODE2;
				mode = 2;
				// Save original values
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
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				blinkRedLed();
			}
			if (isButtonPressed(0)) {
				status = MODE3;
				mode = 3;
				tempYellow = yellowTime;  // Initialize temp value
				updateBufferYLine(mode);       // Đổi X thành Y
				updateBufferXLine(tempYellow); // Đổi Y thành X
				clearTrafficLight();
				break;
			}
			if (isButtonPressed(1)) {
				if (tempRed < 99) tempRed++;
				else tempRed = 1;
				updateBufferXLine(tempRed);    // Đổi Y thành X
			}
			break;
		}
		case MODE3: {
			if (timer_flag[3] == 1) {
				setTimer(3, 500);
				blinkYellowLed();
			}
			if (isButtonPressed(0)) {
				status = MODE4;
				mode = 4;
				tempGreen = greenTime;  // Initialize temp value
				updateBufferYLine(mode);       // Đổi X thành Y
				updateBufferXLine(tempGreen); // Đổi Y thành X
				clearTrafficLight();
				break;
			}
			if (isButtonPressed(1)) {
				if (tempYellow < 99) tempYellow++;
				else tempYellow = 1;
				updateBufferXLine(tempYellow);    // Đổi Y thành X
			}
			break;
		}
		case MODE4: {
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
				updateBufferXLine(tempGreen);    // Đổi Y thành X
			}
			break;
		}
		default: {
			break;
		}
	}
}
