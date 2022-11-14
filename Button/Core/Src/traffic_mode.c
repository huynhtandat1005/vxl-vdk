/*
 * traffic_mode.c
 *
 *  Created on: Nov 13, 2022
 *      Author: huynh
 */

#include "traffic_mode.h"
#include "button.h"

void mode_run(){
	switch (status) {
		case 0:
			display1(0);
			switch (color1) {
				case INIT1:
					HAL_GPIO_WritePin(red_1_GPIO_Port, red_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(yellow_1_GPIO_Port, yellow_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(green_1_GPIO_Port, green_1_Pin, GPIO_PIN_RESET);
					color1 = RED1;
					setTimer1(red_a*100);
					setTimer2(1);
					break;
				case RED1:
					HAL_GPIO_WritePin(red_1_GPIO_Port, red_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(yellow_1_GPIO_Port, yellow_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(green_1_GPIO_Port, green_1_Pin, GPIO_PIN_RESET);

					if(timer2_flag == 1){
						display4(red1);
						red1--;
						if(red1 <= 0) red1 = red_a;
						setTimer2(100);
					}

					if(timer1_flag == 1) {
						color1 = GREEN1;
						setTimer1(green_a*100);
					}
					break;
				case YELLOW1:
					HAL_GPIO_WritePin(red_1_GPIO_Port, red_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(yellow_1_GPIO_Port, yellow_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(green_1_GPIO_Port, green_1_Pin, GPIO_PIN_RESET);

					if(timer2_flag == 1){
						display4(yellow1);
						yellow1--;
						if(yellow1 <= 0) yellow1 = yellow_a;
						setTimer2(100);
					}

					if(timer1_flag == 1) {
						color1 = RED1;
						setTimer1(red_a*100);
					}
					break;
				case GREEN1:
					HAL_GPIO_WritePin(red_1_GPIO_Port, red_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(yellow_1_GPIO_Port, yellow_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(green_1_GPIO_Port, green_1_Pin, GPIO_PIN_SET);

					if(timer2_flag == 1){
						display4(green1);
						green1--;
						if(green1 <= 0) green1 = green_a;
						setTimer2(100);
					}

					if(timer1_flag == 1) {
						color1 = YELLOW1;
						setTimer1(yellow_a*100);
					}
					break;

				default:
					break;
			}

			switch (color2) {
				case INIT2:
					HAL_GPIO_WritePin(red_2_GPIO_Port, red_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(yellow_2_GPIO_Port, yellow_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(green_2_GPIO_Port, green_2_Pin, GPIO_PIN_RESET);
					color2 = GREEN2;
					setTimer3(green_a*100);
					setTimer4(1);
					break;
				case RED2:
					HAL_GPIO_WritePin(red_2_GPIO_Port, red_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(yellow_2_GPIO_Port, yellow_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(green_2_GPIO_Port, green_2_Pin, GPIO_PIN_RESET);

					if(timer4_flag == 1){
						display3(red2);
						red2--;
						if(red2 <= 0) red2 = red_a;
						setTimer4(100);
					}

					if(timer3_flag == 1) {
						color2 = GREEN2;
						setTimer3(green_a*100);
					}
					break;
				case YELLOW2:
					HAL_GPIO_WritePin(red_2_GPIO_Port, red_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(yellow_2_GPIO_Port, yellow_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(green_2_GPIO_Port, green_2_Pin, GPIO_PIN_RESET);

					if(timer4_flag == 1){
						display3(yellow2);
						yellow2--;
						if(yellow2 <= 0) yellow2 = yellow_a;
						setTimer4(100);
					}

					if(timer3_flag == 1) {
						color2 = RED2;
						setTimer3(red_a*100);
					}
					break;
				case GREEN2:
					HAL_GPIO_WritePin(red_2_GPIO_Port, red_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(yellow_2_GPIO_Port, yellow_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(green_2_GPIO_Port, green_2_Pin, GPIO_PIN_SET);

					if(timer4_flag == 1){
						display3(green2);
						green2--;
						if(green2 <= 0) green2 = green_a;
						setTimer4(100);
					}

					if(timer3_flag == 1) {
						color2 = YELLOW2;
						setTimer3(yellow_a*100);
					}
					break;

				default:
					break;
			}

			if(MODE_PRESSED() == 1){
				status = 1;
			}
			break;
		case 1:
			display1(1);
			display2(red_a);
			if(red_a >= 10) red_a = 1;
			if(TIME_PRESSED() == 1){
				red_a++;
			}
			if(MODE_PRESSED() == 1){
				status = 2;
			}
			if(SAVE_PRESSED() == 1){
				status = 0;
			}
			break;
		case 2:
			display1(2);
			display2(yellow_a);
			if(yellow_a >= 10) yellow_a = 1;
			if(TIME_PRESSED() == 1){
				yellow_a++;
			}
			if(SAVE_PRESSED() == 1){
				status = 0;
			}
			if(MODE_PRESSED() == 1){
				status = 3;
			}
			break;
		case 3:
			display1(3);
			display2(green_a);
			if(green_a >= 10) green_a = 1;
			if(TIME_PRESSED() == 1){
				green_a++;
			}
			if(SAVE_PRESSED() == 1){
				status = 0;
			}
			if(MODE_PRESSED() == 1){
				status = 0;
			}
			break;
		default:
			break;
	}
}
