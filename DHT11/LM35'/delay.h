/**
  ******************************************************************************
  * @file		delay.h
  * @author	www.hocdientu123.vn
  * @date		10 January 2019
  ******************************************************************************
  */
	
#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f10x.h"
void DelayInit(void);
void Delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif
