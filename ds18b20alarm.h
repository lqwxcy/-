#ifndef __DS18B20ALARM_H__
#define __DS18B20ALARM_H__
#include"config.h"

extern bit H_Alarm;	//���������¶ȱ�����־λ
extern bit L_Alarm;

extern  S8 idata Alarm_Temp[ 2 ] ;	//�¶ȱ���ֵ

extern  u8 idata Alarm_H_L_Str[16];

void Alarm_Temperature();//�¶ȱ�������

#endif