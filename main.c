/*********************************************************** 
文件名称： 主函数
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月12日22:20:11
修改记录：
总结 ：   1：今天搞了4个钟，收获最大是要看电路图，忘记加一个上拉电阻，时钟时间跑不准
		  2：2012年12月18日20:33:21加入显示节日函数	
		  3：2012年12月20日18:58:58加入温度显示函数
		  4: 全局变量用多了将会超出KEIL	默认的直接寻址的DATA区且DATA区只有128字节
		  5: DS18B20也加4.7K上拉电阻
***********************************************************/
#include"LCD12864.h"
#include"delay.h"
#include"ds1302.h"
#include"timeadjust.h"
#include"keyscan.h"
#include"keypro.h"
#include"disfestival.h"
#include"ds18b20.h"
#include"ds18b20distemp.h"
#include"ds18b20alarm.h"
//#include<reg52.h>
//#include<string.h"

/*------------------------------------------
 	定义临时变量
-------------------------------------------*/
u8 *WEEK[] = {"SUM","MON","TUS","WEN","THU","FRI","SAT"};
sbit LED1 = P3^7;//温度高于上限LED1闪烁
sbit LED2 = P3^6; //温度高于下限LED2闪烁
u16 TimCnt = 0;
sbit BEEP = P3^5;

/*********************************************************** 
函数名称： 定时器T0 初始化
函数功能： 	
入口参数： 	 
出口参数： 
备 注： 
***********************************************************/
void Time0_Init(void)
{
	TMOD |= 0x01;  // 定时器T0工作在方式1
	TH0 = - 1000  / 256;
	TL0 = - 1000  % 256;	
	EA  = 1;			//打开总中断
	ET0 = 1;		//允许T0中
	//TR0 = 1;		//开启定时器T0中断 
}

/*********************************************************** 
函数名称： 定时器T0中断函数
函数功能： 定时每2ms刷新数码管
入口参数： 	 
出口参数： 
备 注： 
***********************************************************/
void Time0_ISR() interrupt 1
{
	TH0 = - 1000  / 256;
	TL0 = - 1000  % 256;
	BEEP = !BEEP;
	if( ++TimCnt == 200 )
	{
		TimCnt = 0;
		if( H_Alarm )
			LED1 = ~LED1;
		else
			LED1 = 1;
		if( L_Alarm )
			LED2 = ~LED2;
		else
			LED2 = 1;
		TR0 = 0; //关闭定时器
	}	
}


void main()
{
	u8 keynum;
	Time0_Init();//定时器T0初始化
	Set_DS18B20_Alarm_Temp();//设置DS18B20温度的报警值，且写入ds18b20里
	ds18b20_ReadTemperature();////读取温度值分别放在Temp_Value[]（存放温度值）与Temp_Alarm[]（存放报警值
	Init_DS18B20();//ds18b20初始化	
	Init_DS1302();//ds1302初始化，是对时时间
	Init_LCD12864();//液晶初始化
	DelayMs( 1 );
	while( 1 )
	{
		ds18b20_ReadTemperature();//读取温度值分别放在Temp_Value[]（存放温度值）与Temp_Alarm[]（存放报警值
		keynum = KeyScan();//读取按键的
		if( adjust_index == -1)
		{
			GetTime();//获取时间	
			Format_Time( DataTime[ 6 ],  LCD_DIS_BUFFER1 + 2 );
			Format_Time( DataTime[ 4 ],  LCD_DIS_BUFFER1 + 6 );
			Format_Time( DataTime[ 3 ],  LCD_DIS_BUFFER1 + 10 );

			Format_Time( DataTime[ 2 ],  LCD_DIS_BUFFER2 + 0 );
			Format_Time( DataTime[ 1 ],  LCD_DIS_BUFFER2 + 4 );
			Format_Time( DataTime[ 0 ],  LCD_DIS_BUFFER2 + 8 );
			strcpy( LCD_DIS_BUFFER2 + 13, WEEK[ DataTime[ 5 ] - 1]);

		   	LCD_PutString( 0, 1, LCD_DIS_BUFFER1);
		   	LCD_PutString( 0, 2, LCD_DIS_BUFFER2);
		}

		Dis_Festival();	//显示公历节日 

		if( iS_DS18B20_OK == 1 )
		{	
			if( H_Alarm == 1 || L_Alarm == 1  )	
				TR0 = 1;
			else 
				TR0 = 0;	
			ds18b20_Display_Temperature();//温度转换	
		}
		if(  keynum != 0xff )
		{
			KeyPro( keynum );	 //一边调整一边显示

			Format_Time( DataTime[ 6 ],  LCD_DIS_BUFFER1 + 2 );
			Format_Time( DataTime[ 4 ],  LCD_DIS_BUFFER1 + 6 );
			Format_Time( DataTime[ 3 ],  LCD_DIS_BUFFER1 + 10 );
		
		   	LCD_PutString( 0, 1, LCD_DIS_BUFFER1);
		
			Format_Time( DataTime[ 2 ],  LCD_DIS_BUFFER2 + 0 );
			Format_Time( DataTime[ 1 ],  LCD_DIS_BUFFER2 + 4 );
			Format_Time( DataTime[ 0 ],  LCD_DIS_BUFFER2 + 8 );
		   	LCD_PutString( 0, 2, LCD_DIS_BUFFER2);	
		}
		
						
	}
}
