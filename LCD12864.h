#ifndef __LCD12864_H__
#define __LCD12864_H__
#include"config.h"

void Check_Busy();//Һ���ȴ�

void Write_Com( u8 com );//дҺ��ָ��	

void Write_Data( u8 dat );//д���ݵ�Һ��ָ 

void Init_LCD12864();//Һ����ʼ��

void  DisplayCGRAM( u8 x, u8 y );//��ʾ�û��Զ����ַ���ָ����λ����ʾ

void LCD_PutString( u8 x, u8 y, u8 *s );//��ʾ�û��Զ����ַ�����ָ����λ����ʾ




#endif