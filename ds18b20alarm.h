#ifndef __DS18B20ALARM_H__
#define __DS18B20ALARM_H__
#include"config.h"

extern bit H_Alarm;	//定义两个温度报警标志位
extern bit L_Alarm;

extern  S8 idata Alarm_Temp[ 2 ] ;	//温度报警值

extern  u8 idata Alarm_H_L_Str[16];

void Alarm_Temperature();//温度报警处理

#endif