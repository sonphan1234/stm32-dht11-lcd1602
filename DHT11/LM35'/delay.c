/**
  ******************************************************************************
  * @file		delay.c
  * @author	www.hocdientu123.vn
  * @date		25/06/2019
  ******************************************************************************
  */
#include "delay.h"
// For store tick counts in us
void Delay_ms(uint32_t _time);
void Delay_ms(uint32_t _time){
	uint32_t i,j;
	for(i = 0; i < _time; i++){
		for(j = 0; j < 0x2AFF; j++);
	}
}
