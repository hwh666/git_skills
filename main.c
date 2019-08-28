#include "ST_Include.h" 
//用到那个外设先看对应的.c文件最上面的说明（如果有的话） 
int main()	
{
	ST_System_Init();
	ST_SysTick_Init();
	
	
	ST_Led_Init();			//RGB灯
	ST_Beep_Init();		 	//蜂鸣器
	ST_Key_Init();  	 	//按键
	ST_Switch_Init();	 	//拨码开关
	
	ST_UART3_Init(115200);  //STM32(串口1)---->TI(串口3)     STM32发送姿态信息
                             //TI(串口3)   ---->STM32(串口1)  STM32接收控制信息
    ST_UART5_Init(115200);  //TI(串口5)---->Openmv     TI发送模式与高度信息
                             //Openmv   ---->TI(串口5)  TI接收位置信息
    
//	ST_Timer0_Both_Init(2000,50000);
//	ST_PWM1_Init();
//	ST_PWM1_Set(0.5f, 0.95f, 0.23f, 0.432f, 0.11f,0.66f, 0.78f, 0.654f);
	
	
	ST_OLED_Init();
//	OLED_ShowString(0,0,"NUEDC");
    OLED_ShowString(10,0,"H   F   X   Y");
    while(1)
    {		
		SchedulerRun();	//任务列表查看ST_Tasks.c		
    }
}

