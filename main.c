/*********************************************************** 
�ļ����ƣ� ������
�� �ߣ�    LQW
�� ����    0.01
˵ ����    
ʱ�� ��    2012��12��12��22:20:11
�޸ļ�¼��
�ܽ� ��   1���������4���ӣ��ջ������Ҫ����·ͼ�����Ǽ�һ���������裬ʱ��ʱ���ܲ�׼
		  2��2012��12��18��20:33:21������ʾ���պ���	
		  3��2012��12��20��18:58:58�����¶���ʾ����
		  4: ȫ�ֱ����ö��˽��ᳬ��KEIL	Ĭ�ϵ�ֱ��Ѱַ��DATA����DATA��ֻ��128�ֽ�
		  5: DS18B20Ҳ��4.7K��������
***********************************************************/
#include"LCD12864.h"
#include"delay.h"
#include"ds1302.h"
#include"timeadjust.h"
#include"keyscan.h"
#include"keypro.h"
#include"disfestival.h"
#include"ds18b20.h"
#include"ds18b20distemp.h"
#include"ds18b20alarm.h"
//#include<reg52.h>
//#include<string.h"

/*------------------------------------------
 	������ʱ����
-------------------------------------------*/
u8 *WEEK[] = {"SUM","MON","TUS","WEN","THU","FRI","SAT"};
sbit LED1 = P3^7;//�¶ȸ�������LED1��˸
sbit LED2 = P3^6; //�¶ȸ�������LED2��˸
u16 TimCnt = 0;
sbit BEEP = P3^5;

/*********************************************************** 
�������ƣ� ��ʱ��T0 ��ʼ��
�������ܣ� 	
��ڲ����� 	 
���ڲ����� 
�� ע�� 
***********************************************************/
void Time0_Init(void)
{
	TMOD |= 0x01;  // ��ʱ��T0�����ڷ�ʽ1
	TH0 = - 1000  / 256;
	TL0 = - 1000  % 256;	
	EA  = 1;			//�����ж�
	ET0 = 1;		//����T0��
	//TR0 = 1;		//������ʱ��T0�ж� 
}

/*********************************************************** 
�������ƣ� ��ʱ��T0�жϺ���
�������ܣ� ��ʱÿ2msˢ�������
��ڲ����� 	 
���ڲ����� 
�� ע�� 
***********************************************************/
void Time0_ISR() interrupt 1
{
	TH0 = - 1000  / 256;
	TL0 = - 1000  % 256;
	BEEP = !BEEP;
	if( ++TimCnt == 200 )
	{
		TimCnt = 0;
		if( H_Alarm )
			LED1 = ~LED1;
		else
			LED1 = 1;
		if( L_Alarm )
			LED2 = ~LED2;
		else
			LED2 = 1;
		TR0 = 0; //�رն�ʱ��
	}	
}


void main()
{
	u8 keynum;
	Time0_Init();//��ʱ��T0��ʼ��
	Set_DS18B20_Alarm_Temp();//����DS18B20�¶ȵı���ֵ����д��ds18b20��
	ds18b20_ReadTemperature();////��ȡ�¶�ֵ�ֱ����Temp_Value[]������¶�ֵ����Temp_Alarm[]����ű���ֵ
	Init_DS18B20();//ds18b20��ʼ��	
	Init_DS1302();//ds1302��ʼ�����Ƕ�ʱʱ��
	Init_LCD12864();//Һ����ʼ��
	DelayMs( 1 );
	while( 1 )
	{
		ds18b20_ReadTemperature();//��ȡ�¶�ֵ�ֱ����Temp_Value[]������¶�ֵ����Temp_Alarm[]����ű���ֵ
		keynum = KeyScan();//��ȡ������
		if( adjust_index == -1)
		{
			GetTime();//��ȡʱ��	
			Format_Time( DataTime[ 6 ],  LCD_DIS_BUFFER1 + 2 );
			Format_Time( DataTime[ 4 ],  LCD_DIS_BUFFER1 + 6 );
			Format_Time( DataTime[ 3 ],  LCD_DIS_BUFFER1 + 10 );

			Format_Time( DataTime[ 2 ],  LCD_DIS_BUFFER2 + 0 );
			Format_Time( DataTime[ 1 ],  LCD_DIS_BUFFER2 + 4 );
			Format_Time( DataTime[ 0 ],  LCD_DIS_BUFFER2 + 8 );
			strcpy( LCD_DIS_BUFFER2 + 13, WEEK[ DataTime[ 5 ] - 1]);

		   	LCD_PutString( 0, 1, LCD_DIS_BUFFER1);
		   	LCD_PutString( 0, 2, LCD_DIS_BUFFER2);
		}

		Dis_Festival();	//��ʾ�������� 

		if( iS_DS18B20_OK == 1 )
		{	
			if( H_Alarm == 1 || L_Alarm == 1  )	
				TR0 = 1;
			else 
				TR0 = 0;	
			ds18b20_Display_Temperature();//�¶�ת��	
		}
		if(  keynum != 0xff )
		{
			KeyPro( keynum );	 //һ�ߵ���һ����ʾ

			Format_Time( DataTime[ 6 ],  LCD_DIS_BUFFER1 + 2 );
			Format_Time( DataTime[ 4 ],  LCD_DIS_BUFFER1 + 6 );
			Format_Time( DataTime[ 3 ],  LCD_DIS_BUFFER1 + 10 );
		
		   	LCD_PutString( 0, 1, LCD_DIS_BUFFER1);
		
			Format_Time( DataTime[ 2 ],  LCD_DIS_BUFFER2 + 0 );
			Format_Time( DataTime[ 1 ],  LCD_DIS_BUFFER2 + 4 );
			Format_Time( DataTime[ 0 ],  LCD_DIS_BUFFER2 + 8 );
		   	LCD_PutString( 0, 2, LCD_DIS_BUFFER2);	
		}
		
						
	}
}
