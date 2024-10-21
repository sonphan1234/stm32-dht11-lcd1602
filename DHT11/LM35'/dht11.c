#include "dht11.h"
#include "timer2.h"

void DHT11_Init(void)
{
	GPIO_InitTypeDef gpioInit;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpioInit.GPIO_Mode = GPIO_Mode_Out_OD;
	gpioInit.GPIO_Pin = GPIO_Pin_8;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &gpioInit);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_8);
}

uint8_t DHT11_Read(uint8_t *pu8Data)
{
	uint16_t u16Tim;
	uint8_t u8Buff[5];
	uint8_t u8CheckSum;
	uint8_t i;
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	delay_ms(20);
	GPIO_SetBits(GPIOB, GPIO_Pin_8);
	
	/* doi chan PB8 len cao */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 10) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if (u16Tim >= 10) {
		return 0;
	}
	
	/* doi chan PB8 xuong thap */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 45) {
		if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if ((u16Tim >= 45) || (u16Tim <= 5)) {
		return 0;
	}
	
	/* doi chan PB8 len cao */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 90) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if ((u16Tim >= 90) || (u16Tim <= 70)) {
		return 0;
	}
	
	/* doi chan PB8 xuong thap */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 95) {
		if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if ((u16Tim >= 95) || (u16Tim <= 75)) {
		return 0;
	}
	
	/* nhan byte so 1 */
	for (i = 0; i < 8; ++i) {
		/* doi chan PB8 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* doi chan PB8 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[0] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[0] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[0] &= ~1;
		}
	}
	
	/* nhan byte so 2 */
	for (i = 0; i < 8; ++i) {
		/* doi chan PB8 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* doi chan PB8 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[1] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[1] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[1] &= ~1;
		}
	}
	
	/* nhan byte so 3 */
	for (i = 0; i < 8; ++i) {
		/* doi chan PB8 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* doi chan PB8 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[2] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[2] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[2] &= ~1;
		}
	}
	
	/* nhan byte so 4 */
	for (i = 0; i < 8; ++i) {
		/* doi chan PB8 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* doi chan PB8 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[3] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[3] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[3] &= ~1;
		}
	}
	
	/* nhan byte so 5 */
	for (i = 0; i < 8; ++i) {
		/* doi chan PB8 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* doi chan PB8 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[4] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[4] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[4] &= ~1;
		}
	}
	
	u8CheckSum = u8Buff[0] + u8Buff[1] + u8Buff[2] + u8Buff[3];
	if (u8CheckSum != u8Buff[4]) {
		return 0;
	}
	
	for (i = 0; i < 4; ++i) {
		pu8Data[i] = u8Buff[i];
	}
	
	return 1;
}
