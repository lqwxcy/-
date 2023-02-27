/*********************************************************** 
�ļ����ƣ� ����������
�� �ߣ�    LQW
�� ����    0.01
˵ ����    
ʱ�� ��    2012��12��15��20:41:16
�޸ļ�¼��
�ܽ� ��   	
***********************************************************/
#include"keypro.h"
#include"timeadjust.h"
#include"LCD12864.h"
#include"ds1302.h"
#include"disfestival.h"
#include"ds18b20alarm.h"
#include"ds18b20.h"
#include"delay.h"
#include"ds18b20distemp.h"


u8 LCD_DIS_BUFFER2[] = {"00ʱ00��00��    "};//�ڶ�������ʾ���� 12
u8 LCD_DIS_BUFFER1[] = {"2000��00��00��"};//��һ������ʾ���� 
u8 Change_Flag[] = {' ','M','H','D','M',' ','Y'};
//u8 Change_Flag[] = {" ,��,ʱ,��,��, ,��"};
//u8 *Change_Flag[] = {" ","��","ʱ","��","��"," ","��",};
//u8 *temp;
/*********************************************************** 
�������ƣ� 	 void KeyPro( u8 keyvalue )
�������ܣ� 	 ����������	   
��ڲ����� 	 keyvalue�������Ƕ�ȡ����ɨ�躯�����ص�ֵ  
���ڲ����� 	  
�� ע�� 
***********************************************************/
void KeyPro( u8 keyvalue )
{
	switch( keyvalue )
	{
		case 1: //ѡ��������󰴼�
				while( P1 != 0xff );
				if( adjust_index == -1 || adjust_index == 1 )
					adjust_index = 7;
				adjust_index--;//ÿ��һ������������Ϳ���ѡ��������� 
				if( adjust_index == 5 )
					adjust_index = 4;
				 
				LCD_DIS_BUFFER2[ 13 ] = '[';
				LCD_DIS_BUFFER2[ 14 ]  = Change_Flag[ adjust_index ];
				//strcpy( LCD_DIS_BUFFER2 + 13,temp );
				//LCD_PutString( 6, 2, temp );
				LCD_DIS_BUFFER2[ 15 ] = ']';		
			
				break;
		case 2:	
				DataTime_Adjust( 1 );
			    break;
		case 3: 
				DataTime_Adjust( -1 );
				break;
		case 4:
				Init_DS1302();
				LCD_DIS_BUFFER2[ 12 ] = ' ';
				LCD_DIS_BUFFER2[ 13 ] = ' ';
				LCD_DIS_BUFFER2[ 14 ] = ' ';
				LCD_DIS_BUFFER2[ 15 ] = ' ';
				//Dis_Festival();
				adjust_index = -1;
				break;
		case 5: 
				ds18b20_ReadTemperature();////��ȡ�¶�ֵ�ֱ����Temp_Value[]������¶�ֵ����Temp_Alarm[]����ű���ֵ
				//Set_DS18B20_Alarm_Temp();
				Alarm_Temperature();//��ʾ���õı����¶�
				DelayMs( 500 );
				break;
		default: keyvalue = 0xff;					
	}
}

