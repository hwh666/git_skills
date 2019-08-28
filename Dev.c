#include "Dev.h"

//--------------------------------------------全局变量
float Cycle_Number;                 ///圈数
float Distance,Distance_Sum;        ///距离
float Actual_Speed;

//--------------------------------------------函数声明
void Key_Init();
void Encoder_Init();
void Encoder_Analysis(float Pulse1);
void ICM20602_Init();
void Dev_Init()
{
    Key_Init();       //按键初始化
    Encoder_Init();   //编码器初始化
    ICM20602_Init();  //陀螺仪初始化
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
    if(gpio_get(KEY8)==0)     //按键按下显示图像和参数
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
    if((!motor_start)&&(gpio_get(KEY1)==0)) //按键按下开始跑
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
    #define wheel_Perimeter  pi*5.6f       ///车轮周长
    #define Wheel_Gear_Number 105.0f       ///车轮齿数
    #define Encoder_Gear_Number 50.0f      ///编码器齿数
  
    Cycle_Number=Pulse1/1024*Encoder_Gear_Number/Wheel_Gear_Number;
    Distance=Cycle_Number*wheel_Perimeter; ///行驶距离
    Distance_Sum=Distance_Sum+Distance;    ///路程累计
    Actual_Speed=Distance*100/4;           ///10ms  s     cm   m      cm/s
}
void ICM20602_Init()
{
    IIC_init();         //模拟IIC 初始化
    icm20602_init();    //六轴陀螺仪初始化
}