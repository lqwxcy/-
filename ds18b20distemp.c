/*********************************************************** 
�ļ����ƣ� DS18b20��ʾ����
�� �ߣ�    LQW
�� ����    0.01
˵ ����    
ʱ�� ��    2012��12��19��20:50:58
�޸ļ�¼��
�ܽ� ��   1��һ��Ҫ��4.7K����������	
***********************************************************/
#include"ds18b20distemp.h"
#include"ds18b20.h"
#include"LCD12864.h"
#include"delay.h"
#include"ds18b20alarm.h"
/*------------------------------------------
 	�����������
-------------------------------------------*/
u8  idata Display_Digit[] = {0,0,0,0};//����ʾ�ĸ��¶���λ	(Ƭ��RAM���Ѱַ��00H-ffH)						  
u8  idata Current_Temp_DIS_BUFFER[]= {"temp:       ��  "};  //����ռ��һ�ֽڣ�˫λ��0x80 �پ�0x82������ʾ�������0x81����ʾ���룩����
u8  code df_Table[] = {0,1,1,2,3,3,4,4,5,6,6,7,8,8,9,9};//����С��λ���ձ�
u8  idata Current = 0;
/*********************************************************** 
�������ƣ� 	 void ds18b20_Display_Temperature())
�������ܣ� 	 ��Һ����ʾds18b20�¶�		   
��ڲ����� 	 
���ڲ����� 	
�� ע�� 
***********************************************************/
void ds18b20_Display_Temperature()
{
	u8 i = 150;	
	S8 	Signed_Current_Temp; //����һ����ǰ�¶ȱ������жϱ����¶���Ϊ��ֵ���Ǹ�ֵ������Ҫ����Ϊ�޷�������
	u8 ng = 0;
	DelayUs( 10 );

	if( (Temp_Value[ 1 ] & 0xf8) == 0xf8 )//�ж��Ƿ�Ϊ������λ:��λ�ֽ�ǰ��λ���ȫ��Ϊ1˵����ȡ���¶��Ǹ�ֵ��������ֵ(1111 1XXX XXXX XXXX(0XF8) )
	{
		Temp_Value[ 1 ] = ~Temp_Value[ 1 ]; //��λȡ��
		Temp_Value[ 0 ]	= ~Temp_Value[ 0 ] + 1; //��λҲȡ����1
		if( Temp_Value[ 0 ] == 0x00 )//����˵��λû������Ϊ0ʱ����λ��ҪTemp_Value[ 1 ]ȡ����1
			Temp_Value[ 1 ]++;
		ng = 1; //���ű�־λ
	}

	Display_Digit[ 0 ] =  df_Table[ Temp_Value[ 0 ] & 0x0f ]; //�жϵ�λ��8���ֽڵ�4λ9��ʾС�����֣�

	//��ȡ�¶��������֣��������ֲ�֪�Ǹ���������
	Current	= ((Temp_Value[ 0 ] & 0xF0 ) >> 4 )	| ((Temp_Value[ 1 ] & 0x07) << 4 );//Temp_Value[ 0 ] & 0xf0��ʾҪȥ��С�����֣�������4λ�������λ��������ֽ�
																				   //�ĵ�4λ������������Ϊ�¶���������

	//�жϵ�ǰ���������¶��¶�ֵ����
	Signed_Current_Temp = ng?  -Current : Current;  //�����ǰ�¶�Ϊ������ǰ���һ������
	//�жϱ����¶�
	H_Alarm = Signed_Current_Temp >= Alarm_Temp[ 0 ] ? 1 : 0;  //�����¶����ޣ�LED����˸
    L_Alarm = Signed_Current_Temp <= Alarm_Temp[ 1 ] ? 1 : 0;  //�����¶����ޣ�LEDҲ����˸
	//����ȡ�������¶ȷֽ�

	Display_Digit[ 3 ] =  Current / 100;
	Display_Digit[ 2 ] =  Current % 100 / 10;
	Display_Digit[ 1 ] =  Current % 10;

	Current_Temp_DIS_BUFFER[ 10 ] =  Display_Digit[ 0 ] + '0';//LCD12864��ʾ����
	Current_Temp_DIS_BUFFER[ 9 ] =  '.';
	Current_Temp_DIS_BUFFER[ 8 ] =  Display_Digit[ 1 ] + '0';
	Current_Temp_DIS_BUFFER[ 7 ] =  Display_Digit[ 2 ] + '0';
	Current_Temp_DIS_BUFFER[ 6 ] =  Display_Digit[ 3 ] + '0';

	if( Display_Digit[ 3 ] == 0 )
		Current_Temp_DIS_BUFFER[ 6 ] = ' ';
	if( Display_Digit[ 3 ] == 0 && Display_Digit[ 2 ] == 0  )
		Current_Temp_DIS_BUFFER[ 7 ] = ' ';
	//�жϸ�ֵ
	if( ng )
	{
		if( Current_Temp_DIS_BUFFER[ 7 ] ==' ')
			Current_Temp_DIS_BUFFER[ 7 ] = '-';

		else if( Current_Temp_DIS_BUFFER[ 6 ] == ' ')
			Current_Temp_DIS_BUFFER[ 6 ] = '-';
		else
			Current_Temp_DIS_BUFFER[ 5 ] = '-';
	}

    LCD_PutString( 0, 3, Current_Temp_DIS_BUFFER );	
}