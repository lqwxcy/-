/*********************************************************** 
文件名称： DS18b20显示函数
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月19日20:50:58
修改记录：
总结 ：   1：一定要接4.7K的上拉电阻	
***********************************************************/
#include"ds18b20distemp.h"
#include"ds18b20.h"
#include"LCD12864.h"
#include"delay.h"
#include"ds18b20alarm.h"
/*------------------------------------------
 	定义操作变量
-------------------------------------------*/
u8  idata Display_Digit[] = {0,0,0,0};//待显示的各温度数位	(片内RAM间接寻址区00H-ffH)						  
u8  idata Current_Temp_DIS_BUFFER[]= {"temp:       ℃  "};  //符号占有一字节，双位（0x80 再就0x82那里显示，如果是0x81则显示乱码）才行
u8  code df_Table[] = {0,1,1,2,3,3,4,4,5,6,6,7,8,8,9,9};//定义小数位对照表
u8  idata Current = 0;
/*********************************************************** 
函数名称： 	 void ds18b20_Display_Temperature())
函数功能： 	 在液晶显示ds18b20温度		   
入口参数： 	 
出口参数： 	
备 注： 
***********************************************************/
void ds18b20_Display_Temperature()
{
	u8 i = 150;	
	S8 	Signed_Current_Temp; //定义一个当前温度变量来判断报警温度是为正值还是负值，所以要定义为无符号类型
	u8 ng = 0;
	DelayUs( 10 );

	if( (Temp_Value[ 1 ] & 0xf8) == 0xf8 )//判断是否为负数高位:高位字节前五位如果全部为1说明读取的温度是负值否则是正值(1111 1XXX XXXX XXXX(0XF8) )
	{
		Temp_Value[ 1 ] = ~Temp_Value[ 1 ]; //高位取反
		Temp_Value[ 0 ]	= ~Temp_Value[ 0 ] + 1; //低位也取反加1
		if( Temp_Value[ 0 ] == 0x00 )//就是说低位没有数据为0时，高位就要Temp_Value[ 1 ]取反加1
			Temp_Value[ 1 ]++;
		ng = 1; //负号标志位
	}

	Display_Digit[ 0 ] =  df_Table[ Temp_Value[ 0 ] & 0x0f ]; //判断低位的8个字节低4位9显示小数部分）

	//获取温度整数部分（整数部分不知是负还是正）
	Current	= ((Temp_Value[ 0 ] & 0xF0 ) >> 4 )	| ((Temp_Value[ 1 ] & 0x07) << 4 );//Temp_Value[ 0 ] & 0xf0表示要去掉小数部分，再右移4位覆盖最低位，方便高字节
																				   //的低4位左移来填充组合为温度整数部分

	//判断当前整数部分温度温度值正负
	Signed_Current_Temp = ng?  -Current : Current;  //如果当前温度为负，在前面加一个负号
	//判断报警温度
	H_Alarm = Signed_Current_Temp >= Alarm_Temp[ 0 ] ? 1 : 0;  //超过温度上限，LED会闪烁
    L_Alarm = Signed_Current_Temp <= Alarm_Temp[ 1 ] ? 1 : 0;  //低于温度下限，LED也会闪烁
	//将读取的整数温度分解

	Display_Digit[ 3 ] =  Current / 100;
	Display_Digit[ 2 ] =  Current % 100 / 10;
	Display_Digit[ 1 ] =  Current % 10;

	Current_Temp_DIS_BUFFER[ 10 ] =  Display_Digit[ 0 ] + '0';//LCD12864显示缓冲
	Current_Temp_DIS_BUFFER[ 9 ] =  '.';
	Current_Temp_DIS_BUFFER[ 8 ] =  Display_Digit[ 1 ] + '0';
	Current_Temp_DIS_BUFFER[ 7 ] =  Display_Digit[ 2 ] + '0';
	Current_Temp_DIS_BUFFER[ 6 ] =  Display_Digit[ 3 ] + '0';

	if( Display_Digit[ 3 ] == 0 )
		Current_Temp_DIS_BUFFER[ 6 ] = ' ';
	if( Display_Digit[ 3 ] == 0 && Display_Digit[ 2 ] == 0  )
		Current_Temp_DIS_BUFFER[ 7 ] = ' ';
	//判断负值
	if( ng )
	{
		if( Current_Temp_DIS_BUFFER[ 7 ] ==' ')
			Current_Temp_DIS_BUFFER[ 7 ] = '-';

		else if( Current_Temp_DIS_BUFFER[ 6 ] == ' ')
			Current_Temp_DIS_BUFFER[ 6 ] = '-';
		else
			Current_Temp_DIS_BUFFER[ 5 ] = '-';
	}

    LCD_PutString( 0, 3, Current_Temp_DIS_BUFFER );	
}