
/**
  ******************************************************************************
  * @file		main.h
  * @author	www.hocdientu123.vn
  * @date		25/06/2019
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
 extern "C" {
#endif
//-----------------------GOI CAC THU VIEN CHUAN---------------------------------//
#include  <stdarg.h>//xu ly so
#include  <string.h>//xu ly kieu chuoi ky tu
#include  <ctype.h>//bao gom cac hoam dung de phan lop cac ky tu boi cac kieu hay dung chuyen doi viet hoa va viet thuong
#include  <stdlib.h>//cac phep toan
#include  <stdio.h>//Cung cap cac dinh dang IN/OUT trong C
//------------------------GOI THU VIEN DUNG CHO PROJECT DANG VIET---------------//
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"              // Device header
#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "timers.h"
//------------------------GOI THU VIEN HAM NGUOI DUNG VIET------------------------//
#include "gpio.h"
#include "lcd16x2.h"
#include "timer2.h"
#include "uart.h"
//------------------------KHAI BAO CAC HAM CHO HAM main.c-------------------------//
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/*****************************END OF FILE****************************************/
