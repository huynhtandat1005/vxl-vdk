/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: huynh
 */

#include "button.h"

int MODE_BT = 0;
int TIME_BT = 0;
int SAVE_BT = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int MODE_key = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;
int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int TIME_key = NORMAL_STATE;

int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;
int KeyReg8 = NORMAL_STATE;
int SAVE_key = NORMAL_STATE;

int TimeOutForKeyPress = 300;
int TimeOutINC_KEY =  300;
int TimeOutDEC_KEY =  300;

int MODE_PRESSED(){
	if(MODE_BT == 1){
		MODE_BT = 0;
		return 1;
	}
	return 0;
}

int TIME_PRESSED(){
	if(TIME_BT == 1){
		TIME_BT = 0;
		return 1;
	}
	return 0;
}

int SAVE_PRESSED(){
	if(SAVE_BT == 1){
		SAVE_BT = 0;
		return 1;
	}
	return 0;
}

void MODE(){
	  KeyReg0 = KeyReg1;
	  KeyReg1 = MODE_key;
	  MODE_key = HAL_GPIO_ReadPin(MODE_GPIO_Port, MODE_Pin);
	  if ((KeyReg0 == KeyReg1) && (KeyReg1 == MODE_key)){
		if (KeyReg2 != MODE_key){
			KeyReg2 = MODE_key;
		  if (MODE_key == PRESSED_STATE){
			TimeOutForKeyPress = 300;
			MODE_BT = 1;
		  }
		}
	  }
}

void TIME(){
	  KeyReg3 = KeyReg4;
	  KeyReg4 = TIME_key;
	  TIME_key = HAL_GPIO_ReadPin(TIME_GPIO_Port, TIME_Pin);
	  if ((KeyReg3 == KeyReg4) && (KeyReg4 == TIME_key)){
		if (KeyReg5 != TIME_key){
			KeyReg5 = TIME_key;
		  if (TIME_key == PRESSED_STATE){
			TimeOutForKeyPress = 300;
			TIME_BT = 1;
		  }
		}
	  }
}

void SAVE(){
	  KeyReg6 = KeyReg7;
	  KeyReg7 = SAVE_key;
	  SAVE_key = HAL_GPIO_ReadPin(SAVE_GPIO_Port, SAVE_Pin);
	  if ((KeyReg6 == KeyReg7) && (KeyReg7 == SAVE_key)){
		if (KeyReg8 != SAVE_key){
			KeyReg8 = SAVE_key;
		  if (SAVE_key == PRESSED_STATE){
			TimeOutForKeyPress = 300;
			SAVE_BT = 1;
		  }
		}
	  }
}

void getKeyInput(){
	MODE();
	TIME();
	SAVE();
}
