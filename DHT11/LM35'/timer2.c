#include "timer2.h"

void timer2_Init(void)
{
	TIM_TimeBaseInitTypeDef timInit;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	timInit.TIM_ClockDivision = TIM_CKD_DIV1;
	timInit.TIM_CounterMode = TIM_CounterMode_Up;
	timInit.TIM_Period = 0xffff;
	timInit.TIM_Prescaler = 72 - 1;
	timInit.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2, &timInit);
	TIM_Cmd(TIM2, ENABLE);
}

void delay_ms(uint32_t t)
{
  while(t)
	{
	  TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 1000) {}
	  --t;
	}
}

void delay_us(uint32_t t)
{
	  TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < t) {}
}
