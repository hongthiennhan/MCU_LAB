/*
 * 7seg.h
 *
 *  Created on: 11 thg 10, 2022
 *      Author: Thiện Nhân
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "main.h"

void resetAllDigits();
void setDigit(int digitSerial);
void setNum2Digit(int a, int b, int c, int d, int e, int f, int g);
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int hour, int minute);
void updateBufferXLine(int value);
void updateBufferYLine(int value);

#endif /* INC_7SEG_H_ */
