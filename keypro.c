/*********************************************************** 
文件名称： 按键处理函数
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月15日20:41:16
修改记录：
总结 ：   	
***********************************************************/
#include"keypro.h"
#include"timeadjust.h"
#include"LCD12864.h"
#include"ds1302.h"
#include"disfestival.h"
#include"ds18b20alarm.h"
#include"ds18b20.h"
#include"delay.h"
#include"ds18b20distemp.h"


u8 LCD_DIS_BUFFER2[] = {"00时00分00秒    "};//第二行所显示内容 12
u8 LCD_DIS_BUFFER1[] = {"2000年00月00日"};//第一行所显示内容 
u8 Change_Flag[] = {' ','M','H','D','M',' ','Y'};
//u8 Change_Flag[] = {" ,分,时,日,月, ,年"};
//u8 *Change_Flag[] = {" ","分","时","日","月"," ","年",};
//u8 *temp;
/*********************************************************** 
函数名称： 	 void KeyPro( u8 keyvalue )
函数功能： 	 按键处理函数	   
入口参数： 	 keyvalue变量就是读取按键扫描函数返回的值  
出口参数： 	  
备 注： 
***********************************************************/
void KeyPro( u8 keyvalue )
{
	switch( keyvalue )
	{
		case 1: //选择调整对象按键
				while( P1 != 0xff );
				if( adjust_index == -1 || adjust_index == 1 )
					adjust_index = 7;
				adjust_index--;//每按一次这个按键，就可以选择调整对象 
				if( adjust_index == 5 )
					adjust_index = 4;
				 
				LCD_DIS_BUFFER2[ 13 ] = '[';
				LCD_DIS_BUFFER2[ 14 ]  = Change_Flag[ adjust_index ];
				//strcpy( LCD_DIS_BUFFER2 + 13,temp );
				//LCD_PutString( 6, 2, temp );
				LCD_DIS_BUFFER2[ 15 ] = ']';		
			
				break;
		case 2:	
				DataTime_Adjust( 1 );
			    break;
		case 3: 
				DataTime_Adjust( -1 );
				break;
		case 4:
				Init_DS1302();
				LCD_DIS_BUFFER2[ 12 ] = ' ';
				LCD_DIS_BUFFER2[ 13 ] = ' ';
				LCD_DIS_BUFFER2[ 14 ] = ' ';
				LCD_DIS_BUFFER2[ 15 ] = ' ';
				//Dis_Festival();
				adjust_index = -1;
				break;
		case 5: 
				ds18b20_ReadTemperature();////读取温度值分别放在Temp_Value[]（存放温度值）与Temp_Alarm[]（存放报警值
				//Set_DS18B20_Alarm_Temp();
				Alarm_Temperature();//显示设置的报警温度
				DelayMs( 500 );
				break;
		default: keyvalue = 0xff;					
	}
}

