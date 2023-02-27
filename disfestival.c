/*********************************************************** 
文件名称： 显示节日函数
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月18日20:33:02
修改记录：
总结 ：   	
***********************************************************/
#include"disfestival.h"
#include"ds1302.h"
#include"LCD12864.h"

/*********************************************************** 
函数名称： 	 void Dis_Festival()
函数功能： 	 显示公历一些节日		   
入口参数： 	  
出口参数： 	  
备 注： 	 
***********************************************************/
void Dis_Festival()
{		
	//要把十进制转换成16进制
	//一月份
	if( DataTime[ 4 ] == 0x01 && DataTime[ 3 ] == 0x01 )//1.1号
		LCD_PutString( 0, 4, "★★新年快乐★");

	else if( DataTime[ 4 ] == 0x01 && DataTime[ 3 ] == 0x40 )//1.28号，
		LCD_PutString( 0, 4, "★★世界麻风日★");

	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x02 )//2.2号
		LCD_PutString( 0, 4, "★★世界湿地日★"); 

	//二月份
	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x0d )//2.13号
		LCD_PutString( 0, 4, "★★明天情人节★");

	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x0e )//2.14号
		LCD_PutString( 0, 4, "★★情人节快乐★");
	
	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x18 )//2.24号
		LCD_PutString( 0, 4, "★★世界青年日★");

	//三月份
	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x01 )//3.1号
		LCD_PutString( 0, 4, "★★国际海豹节★");
		
	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x05 )//3.5号
		LCD_PutString( 0, 4, "★学雷锋纪念日★");	

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x08 )//3.8号
		LCD_PutString( 0, 4, "★★三八妇女节★");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x0c )//3.12号
		LCD_PutString( 0, 4, "★★中国植树节★");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x0e )//3.14号
		LCD_PutString( 0, 4, "★★国际警察日★");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x0f )//3.15号
		LCD_PutString( 0, 4, "★消费者权益日★");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x16 )//3.22号
		LCD_PutString( 0, 4, "★★世界水日★★");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x17 )//3.23号
		LCD_PutString( 0, 4, "★★世界气象日★");

	//四月份

	else if( DataTime[ 4 ] == 0x04 && DataTime[ 3 ] == 0x01 )//4.1号
		LCD_PutString( 0, 4, "★愚★人★节★★");

	else if( DataTime[ 4 ] == 0x04 && DataTime[ 3 ] == 0x07 )//4.7号
		LCD_PutString( 0, 4, "★学世界无烟日★");

	else if( DataTime[ 4 ] == 0x04 && DataTime[ 3 ] == 0x16 )//4.22号
		LCD_PutString( 0, 4, "★★世界地球日★");

	//五月份
	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x01 )//5.1号
		LCD_PutString( 1, 4, "★国际劳动节★");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x04 )//5.4号
		LCD_PutString( 1, 4, "★中国青年节★");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x08 )//5.8号
		LCD_PutString( 0, 4, "★世界红十字日★");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x0c )//5.12号
		LCD_PutString( 1, 4, "★★国际护士节★");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x1f )//5.31号
		LCD_PutString( 0, 4, "★世界无烟草节★");
	//六月份

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x01 )//6.1号
		LCD_PutString( 1, 4, "★★国际儿童节★");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x04 )//6.4号
		LCD_PutString( 1, 4, "★国★际★日★★");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x05 )//6.5号
		LCD_PutString( 1, 4, "★★国际环境日★");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x17 )//6.23号
		LCD_PutString( 0, 4, "★国际奥林匹克日");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x1b )//6.27号
		LCD_PutString( 1, 4, "★★国际禁毒日★");

	//七月份

	else if( DataTime[ 4 ] == 0x07 && DataTime[ 3 ] == 0x01 )//7.1号
		LCD_PutString( 1, 4, "★共产党纪念日★");

	else if( DataTime[ 4 ] == 0x07 && DataTime[ 3 ] == 0x03 )//7.3号
		LCD_PutString( 1, 4, "★★国际合作节★");

	//八月份

	else if( DataTime[ 4 ] == 0x08 && DataTime[ 3 ] == 0x01 )//8.1号
		LCD_PutString( 0, 4, "★建★军★节★★");

	//九月份

	else if( DataTime[ 4 ] == 0x09 && DataTime[ 3 ] == 0x08 )//9.8号
		LCD_PutString( 1, 4, "★新闻工作者日★");

	else if( DataTime[ 4 ] == 0x09 && DataTime[ 3 ] == 0x0a )//9.10号
		LCD_PutString( 1, 4, "★教★师★节★★");

	else if( DataTime[ 4 ] == 0x09 && DataTime[ 3 ] == 0x14 )//9.20号
		LCD_PutString( 0, 4, "★★中国爱牙日★");

	//十月份
	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x01 )//10.1号
		LCD_PutString( 0, 4, "★国★庆★节★★");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x02 )//10.2号
		LCD_PutString( 0, 4, "★国际和平斗争日");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x09 )//10.9号
		LCD_PutString( 0, 4, "★★世界邮政日★");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x14 )//10.14号
		LCD_PutString( 0, 4, "★★世界标准日★");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x0f )//10.15号
		LCD_PutString( 0, 4, "★★国际盲人节★");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x10 )//10.16号
		LCD_PutString( 0, 4, "★★世界粮食日★");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x18)//10.24号
		LCD_PutString( 0, 4, "★★联合国日★★");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x1f )//10.31号
		LCD_PutString( 0, 4, "★世界勤俭日★★");

	//11月份

	else if( DataTime[ 4 ] == 0x0b && DataTime[ 3 ] == 0x01 )//11.1号
		LCD_PutString( 0, 4, "★万★圣★节★★");

	else if( DataTime[ 4 ] == 0x0b && DataTime[ 3 ] == 0x11 )//11.17号
		LCD_PutString( 0, 4, "★★国际学生日★");

	//十二月分

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x01 )//12.1号
		LCD_PutString( 0, 4, "★世界艾滋病日★");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x0a )//12.10号
		LCD_PutString( 0, 4, "★世界人权日★★");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x18 )//12.24号
		LCD_PutString( 0, 4, "★今晚★平安夜★");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x19 )//12.10号
		LCD_PutString( 0, 4, "★圣诞★节快乐★!");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x01 )//12.1号
		LCD_PutString( 0, 4, "★世界艾滋病日★");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x1f )//12.31号
		LCD_PutString( 0, 4, "★明天★新年★★");
    else 
	{
		if( DataTime[ 2 ] >= 0x04 && DataTime[ 2 ] < 0x06 )//凌晨 4：00~6：00
		{
			LCD_PutString( 0, 4, "★★__▲▲__凌晨");	
		}
		
		if( DataTime[ 2 ] >= 0x06 && DataTime[ 2 ] < 0x08 )	//早晨 6：00~8：00
		{
			LCD_PutString( 0, 4, "☆○__▲△__早晨");	
		}

		if( DataTime[ 2 ] >= 0x08 && DataTime[ 2 ] < 0x0c )	//上午 8：00~12：00
		{
			LCD_PutString( 0, 4, "__●__▲▲__上午");	
		}

		if( DataTime[ 2 ] == 0x0c )			  ////中午 12：00
		{
			LCD_PutString( 0, 4, "____▲●▲__中午");	
		}

		if( DataTime[ 2 ] >= 0x0d && DataTime[ 2 ] < 0x12 )//下午 13：00~18：00
		{
			LCD_PutString( 0, 4, "__▲▲__●__下午");	
		}
		
		if( DataTime[ 2 ] >= 0x12 && DataTime[ 2 ] < 0x16 )//凌晨 18：00~22：00
		{
			LCD_PutString( 0, 4, "△▲__●☆__晚上");	
		}

		if( DataTime[ 2 ] >= 0x16 && DataTime[ 2 ] < 0x17 )//凌晨 22：00~23：00
		{
			LCD_PutString( 0, 4, "△▲__★☆__夜里");	
		}

		if( DataTime[ 2 ] >= 0x00 && DataTime[ 2 ] < 0x04 )////深夜 00：00~4：00 
		{
			LCD_PutString( 0, 4, "△▲__★☆__夜里");	
		}
	}







	



}
