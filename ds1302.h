#ifndef __DS1302_H__
#define __DS1302_H__
#include"config.h"

extern u8 DataTime[ 7 ];

void Write_A_Byte_DS1302( u8 dat );//дһ���ֽڵ�ds1302	

void Write_DS1302_Dat( u8 add, u8 dat );//д˫�ֽ����ݵ�ds1302

u8 Read_A_Byte_From_DS1302();//��DS1302�ж�ȡ����

u8 Read_DS1302_ADD_Dat( u8 add );//�Ȱѵ�ַд��ȥds1302���ٴ��Ǹ���ַ�����ȡ���ݷ��ظ�һ������

void Init_DS1302();//ds1302��ʼ�����Ƕ�ʱʱ��

//void  Write_DS1302_Time();//��DS1302дʱ������

void GetTime();//����Ĳ����Ѿ������ݵ�ַ������ı���д��ȥDS1302���棬��������ǰѱ�����ȡ�������в�������ʾ��

void Format_Time( u8 dat, u8 *s );////������ʱ��ֵת��Ϊ�����ַ�

void Init_DS1302();//ds1302��ʼ�����Ƕ�ʱʱ��



#endif 