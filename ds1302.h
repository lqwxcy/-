#ifndef __DS1302_H__
#define __DS1302_H__
#include"config.h"

extern u8 DataTime[ 7 ];

void Write_A_Byte_DS1302( u8 dat );//写一个字节到ds1302	

void Write_DS1302_Dat( u8 add, u8 dat );//写双字节数据到ds1302

u8 Read_A_Byte_From_DS1302();//从DS1302中读取数据

u8 Read_DS1302_ADD_Dat( u8 add );//先把地址写进去ds1302，再从那个地址里面读取数据返回给一个变量

void Init_DS1302();//ds1302初始化，是对时时间

//void  Write_DS1302_Time();//向DS1302写时钟数据

void GetTime();//上面的操作已经把数据地址所代表的变量写进去DS1302里面，这个函数是把变量读取出来进行操作（显示）

void Format_Time( u8 dat, u8 *s );////日期与时间值转换为数字字符

void Init_DS1302();//ds1302初始化，是对时时间



#endif 