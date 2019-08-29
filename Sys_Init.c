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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
    
	Drv_LED_Init();                 //LED���ܳ�ʼ��
    ST_LoadFlashValues();           //������ȡ
	ST_PID_Init();
	
	ST_nRF24L01_Init();
    ST_TIM3_PWM_Init(400,PWM_Polarity_High); //��ʼ�����PWM
    
       
//	ST_Throttle_Calibration();//�����г�У׼
//    ST_Delay_ms(10000);
//    while(1)
//    {
//        for(u8 i=0;i<4;i++)
//        mot(i);
//    }
    ST_flag.mpu_err=ST_ICM20602_Init();
    ST_AK8975_CS_Init();
    
    ST_SerialCom_Init(ST_USART2,460800);     //����
    ST_SerialCom_Init(ST_USART1,115200);     //STM32(����1)---->TI(����3)     STM32������̬��Ϣ
                                              //TI(����3)   ---->STM32(����1)  STM32���տ�����Ϣ
	ST_SerialCom_Init(ST_UART5,806400);      //����

	ST_USB_VCP_Init();
//    if((ST_flag.nrf_err||ST_flag.mpu_err)==0)
//	{
//		ST_Delay_ms(500);
//		ST_flag.Init_ok=1;
//	}
	ST_flag.Init_ok=1;
}

