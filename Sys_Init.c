#include "Sys_Init.h"

ST_flag_t ST_flag;
void mot(u8 i)
{
    switch (i)
    {
    	case 0:
                	TIM3->CCR4 = 6000;
                    TIM3->CCR3 = 4000;
                    TIM3->CCR2 = 4000;
                    TIM3->CCR1 = 4000;
    		break;
    	case 1:
            TIM3->CCR4 = 4000;
                    TIM3->CCR3 = 6000;
                    TIM3->CCR2 = 4000;
                    TIM3->CCR1 = 4000;
    		break;
    	case 2:TIM3->CCR4 = 4000;
                    TIM3->CCR3 = 4000;
                    TIM3->CCR2 = 6000;
                    TIM3->CCR1 = 4000;
    		break;
        case 3:TIM3->CCR4 = 4000;
                    TIM3->CCR3 = 4000;
                    TIM3->CCR2 = 4000;
                    TIM3->CCR1 = 6000;
        break;
    }
    ST_Delay_ms(3000);
}
void ST_Sys_Init(void)
{
	ST_SysTick_Configuration();
<<<<<<< HEAD
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//ï¿½ï¿½ï¿½ï¿½ÏµÍ³ï¿½Ð¶ï¿½ï¿½ï¿½ï¿½È¼ï¿½ï¿½ï¿½ï¿½ï¿½2
    
	Drv_LED_Init();                 //LEDï¿½ï¿½ï¿½Ü³ï¿½Ê¼ï¿½ï¿½
    ST_LoadFlashValues();           //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È¡
	ST_PID_Init();
	
	ST_nRF24L01_Init();
    ST_TIM3_PWM_Init(400,PWM_Polarity_High); //ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ï¿½ï¿½PWM
    
    
    
//	ST_Throttle_Calibration();//ï¿½ï¿½ï¿½ï¿½ï¿½Ð³ï¿½Ð£×¼
=======
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//ÉèÖÃÏµÍ³ÖÐ¶ÏÓÅÏÈ¼¶·Ö×é2
    
	Drv_LED_Init();                 //LED¹¦ÄÜ³õÊ¼»¯
    ST_LoadFlashValues();           //²ÎÊý¶ÁÈ¡
	ST_PID_Init();
	
	ST_nRF24L01_Init();
    ST_TIM3_PWM_Init(400,PWM_Polarity_High); //³õÊ¼»¯µçµ÷PWM
    
    
    
//	ST_Throttle_Calibration();//ÓÍÃÅÐÐ³ÌÐ£×¼
>>>>>>> 59ed72ef5258c3fa99bad363a52df7ea09ffbe7b
//    ST_Delay_ms(10000);
//    while(1)
//    {
//        for(u8 i=0;i<4;i++)
//        mot(i);
//    }
    ST_flag.mpu_err=ST_ICM20602_Init();
    ST_AK8975_CS_Init();
    
<<<<<<< HEAD
    ST_SerialCom_Init(ST_USART2,460800);     //ï¿½ï¿½ï¿½ï¿½
    ST_SerialCom_Init(ST_USART1,115200);     //STM32(ï¿½ï¿½ï¿½ï¿½1)---->TI(ï¿½ï¿½ï¿½ï¿½3)     STM32ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ì¬ï¿½ï¿½Ï¢
                                              //TI(ï¿½ï¿½ï¿½ï¿½3)   ---->STM32(ï¿½ï¿½ï¿½ï¿½1)  STM32ï¿½ï¿½ï¿½Õ¿ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
	ST_SerialCom_Init(ST_UART5,806400);      //ï¿½ï¿½ï¿½ï¿½
=======
    ST_SerialCom_Init(ST_USART2,460800);     //Êý´«
    ST_SerialCom_Init(ST_USART1,115200);     //STM32(´®¿Ú1)---->TI(´®¿Ú3)     STM32·¢ËÍ×ËÌ¬ÐÅÏ¢
                                              //TI(´®¿Ú3)   ---->STM32(´®¿Ú1)  STM32½ÓÊÕ¿ØÖÆÐÅÏ¢
	ST_SerialCom_Init(ST_UART5,806400);      //¹âÁ÷
>>>>>>> 59ed72ef5258c3fa99bad363a52df7ea09ffbe7b
	ST_USB_VCP_Init();
//    if((ST_flag.nrf_err||ST_flag.mpu_err)==0)
//	{
//		ST_Delay_ms(500);
//		ST_flag.Init_ok=1;
//	}
	ST_flag.Init_ok=1;
}

