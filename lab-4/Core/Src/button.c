/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: huynh
 */

#include "button.h"

int button_flag = 0;
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int button_key = NORMAL_STATE;

int button_pressed(){
	if(button_flag == 1){
		button_flag = 0;
		return 1;
	}
	else return 0;
}

void run_button(){
	 KeyReg0 = KeyReg1;
	 KeyReg1 = button_key;
	 button_key = HAL_GPIO_ReadPin(button_GPIO_Port, button_Pin);
	 if ((KeyReg0 == KeyReg1) && (KeyReg1 == button_key)){
		 if (KeyReg2 != button_key){
			 KeyReg2 = button_key;
			 if (button_key == PRESSED_STATE){
				 button_flag = 1;
			 }
		 }
	 }
}

void getKeyInput(){
	run_button();
}
