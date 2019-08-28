#include "Dev.h"

//--------------------------------------------ȫ�ֱ���
float Cycle_Number;                 ///Ȧ��
float Distance,Distance_Sum;        ///����
float Actual_Speed;

//--------------------------------------------��������
void Key_Init();
void Encoder_Init();
void Encoder_Analysis(float Pulse1);
void ICM20602_Init();
void Dev_Init()
{
    Key_Init();       //������ʼ��
    Encoder_Init();   //��������ʼ��
    ICM20602_Init();  //�����ǳ�ʼ��
}

void Key_Init()
{
    gpio_init(KEY8,GPI,0); port_init_NoAlt(KEY8, PULLUP);
    gpio_init(KEY7,GPI,0); port_init_NoAlt(KEY7, PULLUP);        
    gpio_init(KEY5,GPI,0); port_init_NoAlt(KEY5, PULLUP);
    gpio_init(KEY6,GPI,0); port_init_NoAlt(KEY6, PULLUP); 
    gpio_init(KEY2,GPI,0); port_init_NoAlt(KEY2, PULLUP);  
    gpio_init(KEY1,GPI,0); port_init_NoAlt(KEY1, PULLUP);  
    gpio_init(KEY4,GPI,0); port_init_NoAlt(KEY4, PULLUP); 
    gpio_init(KEY3,GPI,0); port_init_NoAlt(KEY3, PULLUP); 
}
void Key_Scan()
{
    static unsigned char motor_start=0;
    if(gpio_get(KEY8)==0)     //����������ʾͼ��Ͳ���
    {
        Show_Image_original(0,0,60,188);
        Show_Image_deal(70,0,60,188); 
        POINT_COLOR=Yellow;
        LCD_ShowString(0,160,"Road_Count :");
        LCD_ShowNum(80,160,Road_Count,3);
        POINT_COLOR=Yellow;
        POINT_COLOR=RED;
        LCD_ShowString(120,160,"Threshold :");
        LCD_ShowNum(200,160,Threshold,3);
        POINT_COLOR=WHITE;
        POINT_COLOR=RED;
        LCD_ShowString(0,180,"change :");
        LCD_ShowNum(80,180,Change_Road,3);
        POINT_COLOR=WHITE;
    }
    if((!motor_start)&&(gpio_get(KEY1)==0)) //�������¿�ʼ��
    {
        motor_start=1;
        systick_delay_ms(500);
        ftm_pwm_duty(ftm0,ftm_ch1,31600);
    }
}
void Encoder_Init()
{
    ftm_quad_init(ftm1);
    port_init_NoAlt (A8, PULLUP );
    port_init_NoAlt (A9, PULLUP );
}

void Encoder_Analysis(float Pulse1)
{
    #define pi 3.14f
    #define wheel_Perimeter  pi*5.6f       ///�����ܳ�
    #define Wheel_Gear_Number 105.0f       ///���ֳ���
    #define Encoder_Gear_Number 50.0f      ///����������
  
    Cycle_Number=Pulse1/1024*Encoder_Gear_Number/Wheel_Gear_Number;
    Distance=Cycle_Number*wheel_Perimeter; ///��ʻ����
    Distance_Sum=Distance_Sum+Distance;    ///·���ۼ�
    Actual_Speed=Distance*100/4;           ///10ms  s     cm   m      cm/s
}
void ICM20602_Init()
{
    IIC_init();         //ģ��IIC ��ʼ��
    icm20602_init();    //���������ǳ�ʼ��
}