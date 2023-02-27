#ifndef __TIMEADJUST_H__
#define __TIMEADJUST_H__
#include"config.h"

extern u8 MonthsDay[ 13 ];
extern S8 adjust_index;

u8 isLeapYear( u16 year );//判断是否为闰年，如果这一年能够被4整除且不能被100整除或能够被400整除说明这一年是闰年

void RefreshWeekDay( void );//刷新星期函数

void DataTime_Adjust( S8 x );//调整时间：年月日时分

#endif