/*********************************************************** 
�ļ����ƣ� DS18b20�¶ȱ�������
�� �ߣ�    LQW
�� ����    0.01
˵ ����    
ʱ�� ��    2012��12��19��20:50:58
�޸ļ�¼��
�ܽ� ��   1��һ��Ҫ��4.7K����������	
		  2: ���������Ͷ����extern  idata S8  Alarm_Temp[ 2 ]���ݲ��ԣ�Ӧ�����ó�extern  S8 idata Alarm_Temp[ 2 ]
***********************************************************/
#include"ds18b20alarm.h"
#include"ds18b20.h"
#include"LCD12864.h"
#include"ds18b20distemp.h"

/*------------------------------------------
 	�����������
-------------------------------------------*/
u8 idata Alarm_H_L_Str[] = "HI:     LI:     ";
						// "0123456789876543"
S8 idata Alarm_Temp[] = {19,12};	//�¶ȱ���ֵ(��������¶�Ϊ���Ϊ14�����¶���ʾΪ14.9��ʱ��LED�ƻ���˸����Ϊ�¶�) 
				
bit H_Alarm = 0;	//���������¶ȱ�����־λ
bit L_Alarm = 0;

/*********************************************************** 
�������ƣ� 	 void Alarm_Temperature()
�������ܣ� 	 �¶ȱ�������
����������		   
��ڲ����� 	 
���ڲ����� 	 
�� ע��    �����Լ����õ��¶ȣ����Լ����õ��¶�ҲҪ�ж������ø���������ֵ����Ҫ�����õ������зֽ������LCD12864��ʾ����
***********************************************************/
void Alarm_Temperature()
{
	//�ж�д��DS18B20������ֵ
	u8 ng = 0;

	if( Alarm_Temp[ 0 ] < 0 )
	{
		Alarm_Temp[ 0 ] = ~Alarm_Temp[ 0 ] + 1;
		ng = 1;
	}
	//�����Լ����õ��¶ȣ����Լ����õ��¶�ҲҪ�ж������ø���������ֵ����Ҫ�����õ������зֽ������LCD12864��ʾ����
	Alarm_H_L_Str[ 4 ] = Alarm_Temp[ 0 ] / 100 + '0'; 
	Alarm_H_L_Str[ 5 ] = Alarm_Temp[ 0 ] / 10 % 10 + '0';
	Alarm_H_L_Str[ 6 ] = Alarm_Temp[ 0 ] % 10 + '0';
	
	if( Alarm_H_L_Str[ 4 ] == 0 )
		Alarm_H_L_Str[ 4 ] = ' ';
	if( Alarm_H_L_Str[ 4 ] == 0 && Alarm_H_L_Str[ 5 ] == 0 )
		Alarm_H_L_Str[ 5 ] = ' ';

	if( ng )//�жϸ�ֵ��־
	{
		if( Alarm_H_L_Str[ 5 ] ==' ' )
			Alarm_H_L_Str[ 5 ] = '-';
		else if( Alarm_H_L_Str[ 4 ] == ' ' )
			Alarm_H_L_Str[ 4 ] = '-';
		else
			Alarm_H_L_Str[ 3 ] = '-';
	}

	ng = 0;	 //���޴���

	if( Alarm_Temp[ 1 ] < 0 )
	{
		Alarm_Temp[ 1 ] = ~Alarm_Temp[ 1 ] + 1;
		ng = 1;
	}

	//�����Լ����õ��¶ȣ����Լ����õ��¶�ҲҪ�ж������ø���������ֵ����Ҫ�����õ������зֽ������LCD12864��ʾ����
	Alarm_H_L_Str[ 12 ] = Alarm_Temp[ 1 ] / 100 + '0';
	Alarm_H_L_Str[ 13 ] = Alarm_Temp[ 1 ] / 10 % 10 + '0';
	Alarm_H_L_Str[ 14 ] = Alarm_Temp[ 1 ] % 10 + '0';

	if( Alarm_H_L_Str[ 12 ] == 0 )
		Alarm_H_L_Str[ 12 ] = ' ';
	if( Alarm_H_L_Str[ 12 ] == 0 && Alarm_H_L_Str[ 13 ] == 0 )
		Alarm_H_L_Str[ 13 ] = ' ';

	if( ng )//�жϸ�ֵ��־
	{
		if( Alarm_H_L_Str[ 13 ] ==' ' )
			Alarm_H_L_Str[ 13 ] = '-';
		else if( Alarm_H_L_Str[ 12 ] == ' ' )
			Alarm_H_L_Str[ 12 ] = '-';
		else
			Alarm_H_L_Str[ 11 ] = '-';
	}

	LCD_PutString( 0, 3, Alarm_H_L_Str );	
}
