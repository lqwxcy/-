#ifndef __DS18B20DISTEMP_H__
#define __DS18B20DISTEMP_H__
#include"config.h"

extern u8 idata Current ;		//������ȡ���������¶�
extern u8 idata Current_Temp_DIS_BUFFER[ 16 ];
extern u8 code df_Table[16];
extern u8 idata Display_Digit[ 4 ];

void ds18b20_Display_Temperature();//��Һ����ʾds18b20�¶�




#endif