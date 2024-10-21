/**
  ******************************************************************************
  * @file		gpio.c
  * @author	www.hocdientu123.vn
  * @date		25/06/2019
  ******************************************************************************
  */
#include "main.h"	
#include "gpio.h"
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  //Enable clock AFIO
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
/*==================================PORTB==========================================*/
	//Enable clock GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//_________________________________OUTPUT__________________________________________
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	//khai bao các chân LCD      		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			// ngõ ra kieu day kéo
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// thiet lap toc do ngo ra cac chan
 GPIO_Init(GPIOB, &GPIO_InitStructure);
	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//_________________________________INTPUT__________________________________________	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, & GPIO_InitStructure);
 }
/********************************* END OF FILE ********************************/
