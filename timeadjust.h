#ifndef __TIMEADJUST_H__
#define __TIMEADJUST_H__
#include"config.h"

extern u8 MonthsDay[ 13 ];
extern S8 adjust_index;

u8 isLeapYear( u16 year );//�ж��Ƿ�Ϊ���꣬�����һ���ܹ���4�����Ҳ��ܱ�100�������ܹ���400����˵����һ��������

void RefreshWeekDay( void );//ˢ�����ں���

void DataTime_Adjust( S8 x );//����ʱ�䣺������ʱ��

#endif