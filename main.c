#include "ST_Include.h" 
//�õ��Ǹ������ȿ���Ӧ��.c�ļ��������˵��������еĻ��� 
int main()	
{
	ST_System_Init();
	ST_SysTick_Init();
	
	
	ST_Led_Init();			//RGB��
	ST_Beep_Init();		 	//������
	ST_Key_Init();  	 	//����
	ST_Switch_Init();	 	//���뿪��
	
	ST_UART3_Init(115200);  //STM32(����1)---->TI(����3)     STM32������̬��Ϣ
                             //TI(����3)   ---->STM32(����1)  STM32���տ�����Ϣ
    ST_UART2_Init(115200);  //TI(����5)---->Openmv     TI����ģʽ��߶���Ϣ
                            //Openmv   ---->TI(����5)  TI����λ����Ϣ
    
//	ST_Timer0_Both_Init(2000,50000);
//	ST_PWM1_Init();
//	ST_PWM1_Set(0.5f, 0.95f, 0.23f, 0.432f, 0.11f,0.66f, 0.78f, 0.654f);
	
	
	ST_OLED_Init();
//	OLED_ShowString(0,0,"NUEDC");
    OLED_ShowString(10,0,"H   F   X   Y");
    while(1)
    {		
		SchedulerRun();	//�����б��鿴ST_Tasks.c		
    }
}

