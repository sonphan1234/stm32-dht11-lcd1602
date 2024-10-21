/**
  ******************************************************************************
  * @file		lcd16x2.h
  * @author	www.hocdientu123.vn
  * @date		25/06/2019
  ******************************************************************************
  */
	
#ifndef __LCD16x2_H
#define __LCD16x2_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"	
//----------KHAI BAO CAC HAM CHO LCD16x2.C
/*
	DINH NGHIA CAC CHAN/PORT
*/
#define LCD_PORT	GPIOB
#define EN_LCD_PIN	GPIO_Pin_13
#define RS_LCD_PIN	GPIO_Pin_15
#define RW_LCD_PIN	GPIO_Pin_14

#define DATA_LCD_PORT	GPIOB
#define D4_LCD				GPIO_Pin_4
#define D5_LCD				GPIO_Pin_5
#define D6_LCD				GPIO_Pin_6
#define D7_LCD				GPIO_Pin_7
/*
	KHAI BÁO CÁC HÀM CHO LCD
*/
void LCD16X2_Init ( void );      								//ham khoi tao LCD16x2
void LCD16X2_Enable(void);       								//ham tao xung EN
void LCD16X2_Clear(void);            						//xoa noi dung hien thi tren LCD16x2
void LCD16X2_Send4Bit(uint8_t data );						//ham goi du lieu 4 bit den LCD16x2
void LCD16X2_SendCommand (uint8_t  command,uint8_t reg );//Goi 1 byte du lieu den LCD
void LCD16X2_Gotoxy(uint8_t  x, uint8_t  y);			//ham thiet lap vi tri con tro
void LCD16X2_PutChar ( uint8_t  data );					//ham viet mot ky tu len LCD16x2
void LCD16X2_PutString (uint8_t *s); 						// hien thi chuoi ky tu ra LCD     
void LCD16X2_NumBer(uint32_t number,uint8_t leng);//ham viet mot chuoi so len LCD16x2
void LCD16X2_controblink_xy(uint8_t x, uint8_t y);	//hàm hien thi con tro nhap nhay
void LCD16X2_contro_off_xy(uint8_t x, uint8_t y);	//hàm tat con tro nhap nhay
#ifdef __cplusplus
}
#endif

#endif
