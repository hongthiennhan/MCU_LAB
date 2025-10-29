/*
 * global.c
 *
 *  Created on: 11 thg 10, 2022
 *      Author: Thiện Nhân
 */

#include "global.h"
int status = INIT;

// Add these definitions
int mode = 0;
int redValue = 0;
int yellowValue = 0;
int greenValue = 0;

// Add temporary variables initialization
int tempRed = 0;
int tempYellow = 0; 
int tempGreen = 0;

void fsm_setting() {
	switch(status) {
		case INIT: {
			if (1) {
				status = AUTO;
			}
			break;
		}
		case AUTO: {
			if (isButtonPressed(0)) {
				status = MAN;
				setTimer(2, 10000); // Timer 3
				setTimer(3, 500); // Timer 4
				clearTrafficLight();
			}
			break;
		}
		case MAN: {
			if (isButtonPressed(2)) {
				status = AUTO;
				break;
			}
			if (timer_flag[2] == 1) {
				status = AUTO;
				break;
			}
			break;
		}
		default: {
			break;
		}
	}
}
