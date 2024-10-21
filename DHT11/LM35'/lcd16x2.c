
/**
  ******************************************************************************
  * @file		lcd16x2.c
  * @author	www.hocdientu123.vn
  * @date		25/06/2019
  ******************************************************************************
  */
#include "lcd16x2.h"
/*******************************************************************************
Noi Dung      :   Gui tin hieu Enable den LCD16X2.
Tham Bien     :   Khong.
Tra Ve        :   Khong.
*******************************************************************************/
 void LCD16X2_Enable(void)
{
    GPIO_SetBits(LCD_PORT,EN_LCD_PIN);//cho chan EN len muc cao
    Delay_us(3);
    GPIO_ResetBits(LCD_PORT,EN_LCD_PIN);//cho chân EN xuong muc thap
    Delay_us(50);
}

/*******************************************************************************
Noi Dung      :   Ham goi 1 byte ra LCD16X2.
Tham Bien     :   data: du liwu can goi, reg: chon thanh ghi du lieu hay thanh ghi lenh
Tra Ve        :   Khong.
*******************************************************************************/
 void LCD16X2_Send4Bit (uint8_t  data )
{
	GPIO_WriteBit(DATA_LCD_PORT, D4_LCD, (BitAction)(data & 0x01) );//=>0x01=0b00000001=> goi bit dau tien
	GPIO_WriteBit(DATA_LCD_PORT, D5_LCD, (BitAction)((data & 0x02) >> 1) );//=>dich sang phai 1 bit roi xuat ra bit thu 2
	GPIO_WriteBit(DATA_LCD_PORT, D6_LCD, (BitAction)((data & 0x04) >> 2) );//=>dich sang phai 1 bit roi xuat ra bit thu 3
	GPIO_WriteBit(DATA_LCD_PORT, D7_LCD, (BitAction)((data & 0x08) >> 3) );//=>dich sang phai 1 bit roi xuat ra bit thu 4
}
 /*******************************************************************************
Noi Dung    :   Gui 1 byte du lieu den LCD.
Tham Bien   :   command: byte du lieu can goi; reg chon thanh ghi lenh hay du lieu
Tra Ve      :   Khong.
********************************************************************************/

void LCD16X2_SendCommand (uint8_t  command,uint8_t reg )
{
	 if(reg==0)//reg=0 hay chan RS=0 thi chon thanh ghi lenh
   {
    GPIO_ResetBits(LCD_PORT,RS_LCD_PIN);	// chon thanh ghi lenh
   }
  else//reg=1 hay RS=1 chon thanh ghi du lieu
   {
    GPIO_SetBits(LCD_PORT,RS_LCD_PIN);		// chon thanh ghi du lieu
   }
		LCD16X2_Send4Bit  ( command >>4 );   /* Gui 4 bit cao */
		LCD16X2_Enable () ;
		LCD16X2_Send4Bit  ( command  );      /* Gui 4 bit thap*/
		LCD16X2_Enable () ;
}
/*******************************************************************************
Noi Dung     :   Xoa noi dung hien thi tren LCD16X2.
Tham Bien    :   Khong.
Tra Ve       :   Khong.
********************************************************************************/
void LCD16X2_Clear()
{
    LCD16X2_SendCommand(0x01,0);// goi lenh dieu khien LCD
    Delay_ms(5);
}
/*******************************************************************************
Noi Dung     :   Khoi tao LCD16X2.
Tham Bien    :   Khong.
Tra Ve       :   Khong.
*******************************************************************************/
 void LCD16X2_Init ( void )
{
		LCD16X2_Send4Bit(0x00);
		Delay_ms(20);
		GPIO_ResetBits(LCD_PORT,RS_LCD_PIN);
		GPIO_ResetBits(LCD_PORT,RW_LCD_PIN);
    GPIO_ResetBits(LCD_PORT,EN_LCD_PIN);
	  LCD16X2_Send4Bit(0x03);// goi du lieu cho LCD16x2 kieu mat dinh, dua con tro ve dau dong dau tin
    LCD16X2_Enable();
    Delay_us(1);
    LCD16X2_Send4Bit(0x02);// goi du lieu cho LCD16x2 kieu mat dinh, dua con tro ve dau dong dau tin
    LCD16X2_Enable();
    Delay_us(5);
    LCD16X2_SendCommand(0x28,0);// ghi lenh: giao thuc 4 bit, hien thi 2 hang, ki tu 5x7
    LCD16X2_SendCommand(0x0C,0);// ghi lenh: cho phep hien thi man hinh
    LCD16X2_Clear();           // xoa toan bo khung hinh
	  LCD16X2_SendCommand(0x06,0);
}
/*******************************************************************************
Noi Dung     :   Thiet lap vi tri con tro LCD16X2.
Tham Bien    :   x: vi tri cot cua con tro. x = 0 -> 15.
                 y: vi tri hang cua con tro. y= 0,1.
Tra Ve       :   Khong.
********************************************************************************/
void LCD16X2_Gotoxy(uint8_t x, uint8_t  y)
{
  uint8_t  address;
  if(!y)
        address = (0x80+x);
  else
        address = (0xC0+x);

  Delay_ms(1);
  LCD16X2_SendCommand(address,0);//ghi lenh dieu khien LCD
  Delay_ms(5);
}
/*******************************************************************************
Noi Dung    :   Viet 1 ki tu len LCD16X2.
Tham Bien   :   Data  :   Gia tri ki tu can hien thi.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD16X2_PutChar (uint8_t data )
{
    LCD16X2_SendCommand(data,1);// ghi du lieu

}
/*******************************************************************************
Noi Dung    :   Viet 1 chuoi ki tu len LCD16X2.
Tham Bien   :   *s   :  chuoi du lieu can hien thi.
Tra Ve      :   Khong.
********************************************************************************/
void LCD16X2_PutString (uint8_t *s)
{

    while (*s)
    {
        LCD16X2_PutChar(*s);
        s++;
    }
}
/*******************************************************************************
Noi Dung    :   Hin thi so len LCD16X2.
Tham Bien   :   number  : so can hiren thi, leng la chieu dai cau chuoi so
Tra Ve      :   Khong.
********************************************************************************/
void LCD16X2_NumBer(uint32_t number,uint8_t leng)
{
//leng la chieu dai cau chuoi so
uint8_t i;
char CacKyTu[leng];//mang chua cac ky tu so
uint8_t temp;

	for(i=0; i<leng; i++)
	{
		temp = number % 10;
		number = number/10;
		CacKyTu[i] = temp;
	}
	for(i=0; i<leng; i++)
	{
		LCD16X2_SendCommand(CacKyTu[leng-1-i] + 48,1);
	}
}
/*******************************************************************************
Noi Dung    :   hàm hien thi con tro nhap nhay
Tham Bien    :   x: vi tri cot cua con tro. x = 0 -> 15.
                 y: vi tri hang cua con tro. y= 0,1.
Tra Ve      :   Khong.
********************************************************************************/
void LCD16X2_controblink_xy(uint8_t x, uint8_t y)
{
		LCD16X2_Gotoxy(x,y);
		LCD16X2_SendCommand(0x0f,0);
}
/*******************************************************************************
Noi Dung    :   hàm tat con tro nhap nhay
Tham Bien    :   x: vi tri cot cua con tro. x = 0 -> 15.
                 y: vi tri hang cua con tro. y= 0,1.
Tra Ve      :   Khong.
********************************************************************************/
void LCD16X2_contro_off_xy(uint8_t x, uint8_t y)
{
	LCD16X2_Gotoxy(x,y);
	LCD16X2_SendCommand(0x0E,0);
}