/*********************************************************** 
文件名称： DS1302时间转换函数
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月15日20:41:16
修改记录：
总结 ：   	
***********************************************************/
#include"timeadjust.h"
#include"ds1302.h"


/*------------------------------------------
 	定义操作变量
-------------------------------------------*/
u8 MonthsDay[] = { 0,31,0,31,30,31,30,31,31,30,31,30,31};//一年中每个月的天数，2月份由年分决定
S8 adjust_index = -1;//当前调节时间对象：年月日时分

/*********************************************************** 
函数名称： 	 u8 isLeapYear( u16 year )
函数功能： 	 判断是否为闰年，如果这一年能够被4整除且不能被100整除或能够被400整除说明这一年是闰年		   
入口参数： 	 year 
出口参数： 	  
备 注： 	 1: 注意年是要大于255，所以要数据类型是int类
***********************************************************/
u8 isLeapYear( u16 year )
{
	return ( year % 4 == 0 && year %100 != 0 || year %400 == 0 );
}

/*********************************************************** 
函数名称： 	 void RefreshWeekDay()
函数功能： 	 刷新星期函数		   
入口参数： 	 无 
出口参数： 	  
备 注： 
***********************************************************/
void RefreshWeekDay( void )
{
	u16 i,week = 5, year; //已知1999.12.31是星期五
	for( i = 2000; i < 2000 + DataTime[ 6 ]; i++ )
	{
		year = 	isLeapYear( i ) ?  366 : 365; //判断是否为闰年，如果是闰年是366天，不是则365天
		week = ( week + year ) % 7;	  //如果是2000年1月1号则是星期六，370 % 7 = 6
	}
	year = 0;	
	for( i = 1; i < DataTime[ i ]; i ++ )
	{
		year = year + MonthsDay[ DataTime[ 4 ] ];	
	}
	year = year + DataTime[ 3 ];
	DataTime[ 5 ] = ( week + year ) % 7;		
}

/*********************************************************** 
函数名称： 	 void DataTime_Adjust( S8 x )
函数功能： 	 调整时间：年月日时分		   
入口参数： 	 x 
出口参数： 	  
备 注： 	1:有正负数据类型是有符号类型
***********************************************************/
void DataTime_Adjust( S8 x )
{
	switch( adjust_index )
	{
		case 6:  //调整年00-99
				if( x == 1 && DataTime[ 6 ] < 99 )
					DataTime[ 6 ]++;
				if( x == -1 && DataTime[ 6 ] > 0 )
					DataTime[ 6 ]--;

				MonthsDay[ 2 ] = isLeapYear( 2000 + DataTime[ 6 ] ) ?  29 : 28;	 //闰年二月份有29天
				if( DataTime[ 3 ] > MonthsDay[ DataTime[ 4 ] ])
					DataTime[ 3 ] = MonthsDay[ DataTime[ 4 ] ];//调整年的时候，月是不变的，但如果那一年（比如2012）则好是闰年二29天，但
																//调整年后是2013却不闰年，二月只有28天 ，那2013年二要就跳到28号
				RefreshWeekDay( );	//调用星期函数
				break;
		case 4: //调整月0-12
				if( x == 1 && DataTime[ 4 ] < 12 )
					DataTime[ 4 ]++;
				if( x == -1 && DataTime[ 4 ] > 1 )
					DataTime[ 4 ]--;

				MonthsDay[ 2 ] = isLeapYear( 2000 + DataTime[ 6 ] ) ?  29 : 28;	 //闰年二月份有29天
				if( DataTime[ 3 ] > MonthsDay[ DataTime[ 4 ] ])
					DataTime[ 3 ] = MonthsDay[ DataTime[ 4 ] ];//调整年的时候，月是不变的，但如果那一年（比如2012）则好是闰年二29天，但
																//调整年后是2013却不闰年，二月只有28天 ，那2013年二要就跳到28号
				RefreshWeekDay( );	//调用星期函数
				break;
		case 3: // 调整日28，29，30，31天

				MonthsDay[ 2 ] = isLeapYear( 2000 + DataTime[ 6 ] ) ?  29 : 28;	 //闰年二月份有29天
				if( x == 1 && DataTime[ 3 ] < MonthsDay[ DataTime[ 4 ] ] )
					DataTime[ 3 ]++;
				if( x == -1 && DataTime[ 3 ] > 0 )
					DataTime[ 3 ]--;

				RefreshWeekDay( );	//调用星期函数
				break;
		case 2://调整时0-23
				if( x == 1 && DataTime[ 2 ] < 23 )
					DataTime[ 2 ]++;
				if( x == -1 && DataTime[ 2 ] > 0 )
					DataTime[ 2 ]--;
				break;
	    case 1://调整分0-59
				if( x == 1 && DataTime[ 1 ] < 59 )
					DataTime[ 1 ]++;
				if( x == -1 && DataTime[ 1 ] > 0 )
					DataTime[ 1 ]--;
				break;				
	}	
}



