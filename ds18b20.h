#ifndef __DS18B20_H__
#define __DS18B20_H__
#include"config.h"

extern bit iS_DS18B20_OK ; //�����¶ȶ�ȡ������־λ

extern u8 Temp_Value[ 2 ]; //����һ���������洢����ȡ���¶�ֵ

u8 Init_DS18B20();//ds18b20��ʼ��

void ds18b20_Write_A_Byte( u8 dat );//��DS18B20дһ���ֽ�����

u8 ds18b20_Read_A_Byte();//��DS18B20��ȡһ���ֽ�����

void ds18b20_ReadTemperature();//��ȡ�¶�ֵ�ֱ����Temp_Value[]������¶�ֵ����Temp_Alarm[]����ű���ֵ

void Set_DS18B20_Alarm_Temp();//����DS18B20�¶ȵı���ֵ����д��ds18b20��

#endif