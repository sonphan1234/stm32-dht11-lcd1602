
#include "main.h"	
//adc: PA1
//button: PA0

#define EVENT0 (1<<0)
#define EVENT1 (1<<1)
#define EVENT_ALLS ((EVENT1<<1) - 1)

void TaskMain(void* p);
void Serial_Display(void* p);
void LCD16x2_Display(void* p);
void Read_Temp(void* p);
uint8_t ch;
char Display1[100];
char Display2[100];
uint8_t u8Buff[4];
uint8_t ButtonState = 3;
EventGroupHandle_t event_hl;

int main (void)
{
  GPIO_Configuration();	// goi ham cau hinh ngo vao ra cho cac PORT
	GPIO_PinRemapConfig (GPIO_Remap_SWJ_JTAGDisable, ENABLE);//bo che do nap JTAGD
	LCD16X2_Init();				//goi ham cau hinh LCD
	LCD16X2_Clear();
	uart_Init();
	DHT11_Init();
	timer2_Init();
	SystemInit();
	SystemCoreClockUpdate();
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // kich hoat or tat clock
	xTaskCreate(TaskMain, "TaskMain", 128, NULL, tskIDLE_PRIORITY, NULL);
	xTaskCreate(LCD16x2_Display, "LCD16x2_Display", 128, NULL, tskIDLE_PRIORITY, NULL); // tao task
	xTaskCreate(Serial_Display, "Serial_Display", 128, NULL, tskIDLE_PRIORITY, NULL);
	xTaskCreate(Read_Temp, "Read_Temp", 128, NULL, 1, NULL);
	vTaskStartScheduler(); // thiet lap lich cho cac task
	return 0;
}

void TaskMain(void* p) // ham dieu khien nut nhan
{
	event_hl = xEventGroupCreate();
	static uint8_t count = 0;
	while(1)
	{
		uint8_t BitCheck = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
		if(BitCheck == 1) count = 0;
		if(BitCheck == 0 && count == 0)
		{
			switch (ButtonState)
			{
				case 1:
					ButtonState = 2;
					break;
				case 2:
					ButtonState = 3;
					break;
				case 3:
					ButtonState = 1;
					break;
			}
			count++;
		}
		if(ButtonState == 1) xEventGroupSetBits(event_hl, EVENT0);
		if(ButtonState == 2)
		{			
			xEventGroupSetBits(event_hl, EVENT1);
			LCD16X2_Clear();
		}
		if(ButtonState == 3) xEventGroupSetBits(event_hl, EVENT_ALLS);
	}
}
void Read_Temp(void* p)
{
					while(1)
	{	
		 /* gui do am */
		
		  DHT11_Read(u8Buff);
			sprintf(Display1, "Do am: %d ", u8Buff[0]);
			sprintf(Display2, "Nhiet do: %d ", u8Buff[2]); 
		  vTaskDelay(500);

	
	}
}
void Serial_Display(void* p)
{
	EventBits_t event;
	while(1)
	{
		event = xEventGroupWaitBits(event_hl, EVENT_ALLS, pdTRUE, pdFALSE, portMAX_DELAY);
		if(event & EVENT1)
		{
			uart_SendStr(Display1);
			uart_SendChar('\n');
			uart_SendStr(Display2);
			uart_SendChar('\n');
			vTaskDelay(500);
		}
	}
}
void LCD16x2_Display(void* p)
{
	EventBits_t event;
	while(1)
	{
		event = xEventGroupWaitBits(event_hl, EVENT_ALLS, pdTRUE, pdFALSE, portMAX_DELAY);
		if(event & EVENT0)
		{
			LCD16X2_Gotoxy(0, 0);
			LCD16X2_PutString(Display1);
			LCD16X2_Gotoxy(9, 0);
	    LCD16X2_PutString("%");
			/* gui nhiet do */
			LCD16X2_Gotoxy(0, 1);
			LCD16X2_PutString(Display2);
			LCD16X2_Gotoxy(12, 1);
	    LCD16X2_PutString("oC");
			vTaskDelay(500);
		}
	}
}
void Delay_ms(uint32_t _time);
void Delay_ms(uint32_t _time){
	uint32_t i,j;
	for(i = 0; i < _time; i++){
		for(j = 0; j < 0x2AFF; j++);
	}
}

void Delay_us(uint32_t _time);
void Delay_us(uint32_t _time){
    uint32_t i, j;
    for (i = 0; i < _time; i++) {
        for (j = 0; j < 0x2A; j++); // Gi? s? dây là m?t giá tr? phù h?p cho delay 1 microsecond
    }
}





