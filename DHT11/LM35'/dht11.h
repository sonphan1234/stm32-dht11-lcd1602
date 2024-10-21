#ifndef _dht11_h_
#define _dht11_h_

#include "stm32f10x.h"

void DHT11_Init(void);
uint8_t DHT11_Read(uint8_t *pu8Data);
	
#endif
