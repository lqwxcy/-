#ifndef __DS18B20_H__
#define __DS18B20_H__
#include"config.h"

extern bit iS_DS18B20_OK ; //定义温度读取正常标志位

extern u8 Temp_Value[ 2 ]; //定义一个数据来存储所读取的温度值

u8 Init_DS18B20();//ds18b20初始化

void ds18b20_Write_A_Byte( u8 dat );//向DS18B20写一个字节数据

u8 ds18b20_Read_A_Byte();//从DS18B20读取一个字节数据

void ds18b20_ReadTemperature();//读取温度值分别放在Temp_Value[]（存放温度值）与Temp_Alarm[]（存放报警值

void Set_DS18B20_Alarm_Temp();//设置DS18B20温度的报警值，且写入ds18b20里

#endif