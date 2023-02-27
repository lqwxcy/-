#ifndef __LCD12864_H__
#define __LCD12864_H__
#include"config.h"

void Check_Busy();//液晶等待

void Write_Com( u8 com );//写液晶指令	

void Write_Data( u8 dat );//写数据到液晶指 

void Init_LCD12864();//液晶初始化

void  DisplayCGRAM( u8 x, u8 y );//显示用户自定义字符，指定的位置显示

void LCD_PutString( u8 x, u8 y, u8 *s );//显示用户自定义字符串，指定的位置显示




#endif