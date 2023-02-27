/*********************************************************** 
文件名称： DS18b20温度报警函数
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月19日20:50:58
修改记录：
总结 ：   1：一定要接4.7K的上拉电阻	
		  2: 把数据类型定义成extern  idata S8  Alarm_Temp[ 2 ]数据不对，应该设置成extern  S8 idata Alarm_Temp[ 2 ]
***********************************************************/
#include"ds18b20alarm.h"
#include"ds18b20.h"
#include"LCD12864.h"
#include"ds18b20distemp.h"

/*------------------------------------------
 	定义操作变量
-------------------------------------------*/
u8 idata Alarm_H_L_Str[] = "HI:     LI:     ";
						// "0123456789876543"
S8 idata Alarm_Temp[] = {19,12};	//温度报警值(如果设置温度为最低为14，但温度显示为14.9度时，LED灯会闪烁，因为温度) 
				
bit H_Alarm = 0;	//定义两个温度报警标志位
bit L_Alarm = 0;

/*********************************************************** 
函数名称： 	 void Alarm_Temperature()
函数功能： 	 温度报警处理
）两个数组		   
入口参数： 	 
出口参数： 	 
备 注：    这是自己设置的温度，但自己设置的温度也要判断是设置负数还是正值，还要对设置的数进行分解才能在LCD12864显示出来
***********************************************************/
void Alarm_Temperature()
{
	//判断写入DS18B20是上限值
	u8 ng = 0;

	if( Alarm_Temp[ 0 ] < 0 )
	{
		Alarm_Temp[ 0 ] = ~Alarm_Temp[ 0 ] + 1;
		ng = 1;
	}
	//这是自己设置的温度，但自己设置的温度也要判断是设置负数还是正值，还要对设置的数进行分解才能在LCD12864显示出来
	Alarm_H_L_Str[ 4 ] = Alarm_Temp[ 0 ] / 100 + '0'; 
	Alarm_H_L_Str[ 5 ] = Alarm_Temp[ 0 ] / 10 % 10 + '0';
	Alarm_H_L_Str[ 6 ] = Alarm_Temp[ 0 ] % 10 + '0';
	
	if( Alarm_H_L_Str[ 4 ] == 0 )
		Alarm_H_L_Str[ 4 ] = ' ';
	if( Alarm_H_L_Str[ 4 ] == 0 && Alarm_H_L_Str[ 5 ] == 0 )
		Alarm_H_L_Str[ 5 ] = ' ';

	if( ng )//判断负值标志
	{
		if( Alarm_H_L_Str[ 5 ] ==' ' )
			Alarm_H_L_Str[ 5 ] = '-';
		else if( Alarm_H_L_Str[ 4 ] == ' ' )
			Alarm_H_L_Str[ 4 ] = '-';
		else
			Alarm_H_L_Str[ 3 ] = '-';
	}

	ng = 0;	 //下限处理

	if( Alarm_Temp[ 1 ] < 0 )
	{
		Alarm_Temp[ 1 ] = ~Alarm_Temp[ 1 ] + 1;
		ng = 1;
	}

	//这是自己设置的温度，但自己设置的温度也要判断是设置负数还是正值，还要对设置的数进行分解才能在LCD12864显示出来
	Alarm_H_L_Str[ 12 ] = Alarm_Temp[ 1 ] / 100 + '0';
	Alarm_H_L_Str[ 13 ] = Alarm_Temp[ 1 ] / 10 % 10 + '0';
	Alarm_H_L_Str[ 14 ] = Alarm_Temp[ 1 ] % 10 + '0';

	if( Alarm_H_L_Str[ 12 ] == 0 )
		Alarm_H_L_Str[ 12 ] = ' ';
	if( Alarm_H_L_Str[ 12 ] == 0 && Alarm_H_L_Str[ 13 ] == 0 )
		Alarm_H_L_Str[ 13 ] = ' ';

	if( ng )//判断负值标志
	{
		if( Alarm_H_L_Str[ 13 ] ==' ' )
			Alarm_H_L_Str[ 13 ] = '-';
		else if( Alarm_H_L_Str[ 12 ] == ' ' )
			Alarm_H_L_Str[ 12 ] = '-';
		else
			Alarm_H_L_Str[ 11 ] = '-';
	}

	LCD_PutString( 0, 3, Alarm_H_L_Str );	
}
