/*********************************************************** 
�ļ����ƣ� ����ɨ�躯��
�� �ߣ�    LQW
�� ����    0.01
˵ ����    
ʱ�� ��    2012��12��15��20:41:16
�޸ļ�¼�� 1��2012��12��20��22:34:54���밴��5
�ܽ� ��   	
***********************************************************/
#include"keyscan.h"

/*********************************************************** 
�������ƣ� 	 u8 KeyScan()
�������ܣ� 	 ����ɨ��	   
��ڲ����� 	 �� 
���ڲ����� 	 key
�� ע�� 
***********************************************************/
u8 KeyScan()
{
	u8 key;
	if( P1 == 0xff )  
		return 0;
	switch( P1 )
	{
		case 0xef: key = 1; break;
		case 0xdf: key = 2; break;
		case 0xbf: key = 3; break;
		case 0x7f: key = 4; break;
		case 0xf7: key = 5; break;
		default: key = 0xff;
	}
	while( P1 != 0xff ); //�ȴ������ͷ�
	return key; 	
}
