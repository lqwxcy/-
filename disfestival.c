/*********************************************************** 
�ļ����ƣ� ��ʾ���պ���
�� �ߣ�    LQW
�� ����    0.01
˵ ����    
ʱ�� ��    2012��12��18��20:33:02
�޸ļ�¼��
�ܽ� ��   	
***********************************************************/
#include"disfestival.h"
#include"ds1302.h"
#include"LCD12864.h"

/*********************************************************** 
�������ƣ� 	 void Dis_Festival()
�������ܣ� 	 ��ʾ����һЩ����		   
��ڲ����� 	  
���ڲ����� 	  
�� ע�� 	 
***********************************************************/
void Dis_Festival()
{		
	//Ҫ��ʮ����ת����16����
	//һ�·�
	if( DataTime[ 4 ] == 0x01 && DataTime[ 3 ] == 0x01 )//1.1��
		LCD_PutString( 0, 4, "���������֡�");

	else if( DataTime[ 4 ] == 0x01 && DataTime[ 3 ] == 0x40 )//1.28�ţ�
		LCD_PutString( 0, 4, "�����������ա�");

	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x02 )//2.2��
		LCD_PutString( 0, 4, "�������ʪ���ա�"); 

	//���·�
	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x0d )//2.13��
		LCD_PutString( 0, 4, "����������˽ڡ�");

	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x0e )//2.14��
		LCD_PutString( 0, 4, "������˽ڿ��֡�");
	
	else if( DataTime[ 4 ] == 0x02 && DataTime[ 3 ] == 0x18 )//2.24��
		LCD_PutString( 0, 4, "������������ա�");

	//���·�
	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x01 )//3.1��
		LCD_PutString( 0, 4, "�����ʺ����ڡ�");
		
	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x05 )//3.5��
		LCD_PutString( 0, 4, "��ѧ�׷�����ա�");	

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x08 )//3.8��
		LCD_PutString( 0, 4, "������˸�Ů�ڡ�");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x0c )//3.12��
		LCD_PutString( 0, 4, "����й�ֲ���ڡ�");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x0e )//3.14��
		LCD_PutString( 0, 4, "�����ʾ����ա�");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x0f )//3.15��
		LCD_PutString( 0, 4, "��������Ȩ���ա�");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x16 )//3.22��
		LCD_PutString( 0, 4, "�������ˮ�ա��");

	else if( DataTime[ 4 ] == 0x03 && DataTime[ 3 ] == 0x17 )//3.23��
		LCD_PutString( 0, 4, "������������ա�");

	//���·�

	else if( DataTime[ 4 ] == 0x04 && DataTime[ 3 ] == 0x01 )//4.1��
		LCD_PutString( 0, 4, "���ޡ��ˡ�ڡ��");

	else if( DataTime[ 4 ] == 0x04 && DataTime[ 3 ] == 0x07 )//4.7��
		LCD_PutString( 0, 4, "��ѧ���������ա�");

	else if( DataTime[ 4 ] == 0x04 && DataTime[ 3 ] == 0x16 )//4.22��
		LCD_PutString( 0, 4, "�����������ա�");

	//���·�
	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x01 )//5.1��
		LCD_PutString( 1, 4, "������Ͷ��ڡ�");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x04 )//5.4��
		LCD_PutString( 1, 4, "���й�����ڡ�");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x08 )//5.8��
		LCD_PutString( 0, 4, "�������ʮ���ա�");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x0c )//5.12��
		LCD_PutString( 1, 4, "�����ʻ�ʿ�ڡ�");

	else if( DataTime[ 4 ] == 0x05 && DataTime[ 3 ] == 0x1f )//5.31��
		LCD_PutString( 0, 4, "���������̲ݽڡ�");
	//���·�

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x01 )//6.1��
		LCD_PutString( 1, 4, "�����ʶ�ͯ�ڡ�");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x04 )//6.4��
		LCD_PutString( 1, 4, "�����ʡ��ա��");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x05 )//6.5��
		LCD_PutString( 1, 4, "�����ʻ����ա�");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x17 )//6.23��
		LCD_PutString( 0, 4, "����ʰ���ƥ����");

	else if( DataTime[ 4 ] == 0x06 && DataTime[ 3 ] == 0x1b )//6.27��
		LCD_PutString( 1, 4, "�����ʽ����ա�");

	//���·�

	else if( DataTime[ 4 ] == 0x07 && DataTime[ 3 ] == 0x01 )//7.1��
		LCD_PutString( 1, 4, "�ﹲ���������ա�");

	else if( DataTime[ 4 ] == 0x07 && DataTime[ 3 ] == 0x03 )//7.3��
		LCD_PutString( 1, 4, "�����ʺ����ڡ�");

	//���·�

	else if( DataTime[ 4 ] == 0x08 && DataTime[ 3 ] == 0x01 )//8.1��
		LCD_PutString( 0, 4, "�ｨ�����ڡ��");

	//���·�

	else if( DataTime[ 4 ] == 0x09 && DataTime[ 3 ] == 0x08 )//9.8��
		LCD_PutString( 1, 4, "�����Ź������ա�");

	else if( DataTime[ 4 ] == 0x09 && DataTime[ 3 ] == 0x0a )//9.10��
		LCD_PutString( 1, 4, "��̡�ʦ��ڡ��");

	else if( DataTime[ 4 ] == 0x09 && DataTime[ 3 ] == 0x14 )//9.20��
		LCD_PutString( 0, 4, "����й������ա�");

	//ʮ�·�
	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x01 )//10.1��
		LCD_PutString( 0, 4, "��������ڡ��");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x02 )//10.2��
		LCD_PutString( 0, 4, "����ʺ�ƽ������");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x09 )//10.9��
		LCD_PutString( 0, 4, "������������ա�");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x14 )//10.14��
		LCD_PutString( 0, 4, "��������׼�ա�");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x0f )//10.15��
		LCD_PutString( 0, 4, "������ä�˽ڡ�");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x10 )//10.16��
		LCD_PutString( 0, 4, "���������ʳ�ա�");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x18)//10.24��
		LCD_PutString( 0, 4, "������Ϲ��ա��");

	else if( DataTime[ 4 ] == 0x0a && DataTime[ 3 ] == 0x1f )//10.31��
		LCD_PutString( 0, 4, "�������ڼ��ա��");

	//11�·�

	else if( DataTime[ 4 ] == 0x0b && DataTime[ 3 ] == 0x01 )//11.1��
		LCD_PutString( 0, 4, "�����ʥ��ڡ��");

	else if( DataTime[ 4 ] == 0x0b && DataTime[ 3 ] == 0x11 )//11.17��
		LCD_PutString( 0, 4, "������ѧ���ա�");

	//ʮ���·�

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x01 )//12.1��
		LCD_PutString( 0, 4, "�����簬�̲��ա�");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x0a )//12.10��
		LCD_PutString( 0, 4, "��������Ȩ�ա��");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x18 )//12.24��
		LCD_PutString( 0, 4, "������ƽ��ҹ��");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x19 )//12.10��
		LCD_PutString( 0, 4, "��ʥ����ڿ��֡�!");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x01 )//12.1��
		LCD_PutString( 0, 4, "�����簬�̲��ա�");

	else if( DataTime[ 4 ] == 0x0c && DataTime[ 3 ] == 0x1f )//12.31��
		LCD_PutString( 0, 4, "�������������");
    else 
	{
		if( DataTime[ 2 ] >= 0x04 && DataTime[ 2 ] < 0x06 )//�賿 4��00~6��00
		{
			LCD_PutString( 0, 4, "���__����__�賿");	
		}
		
		if( DataTime[ 2 ] >= 0x06 && DataTime[ 2 ] < 0x08 )	//�糿 6��00~8��00
		{
			LCD_PutString( 0, 4, "���__����__�糿");	
		}

		if( DataTime[ 2 ] >= 0x08 && DataTime[ 2 ] < 0x0c )	//���� 8��00~12��00
		{
			LCD_PutString( 0, 4, "__��__����__����");	
		}

		if( DataTime[ 2 ] == 0x0c )			  ////���� 12��00
		{
			LCD_PutString( 0, 4, "____�����__����");	
		}

		if( DataTime[ 2 ] >= 0x0d && DataTime[ 2 ] < 0x12 )//���� 13��00~18��00
		{
			LCD_PutString( 0, 4, "__����__��__����");	
		}
		
		if( DataTime[ 2 ] >= 0x12 && DataTime[ 2 ] < 0x16 )//�賿 18��00~22��00
		{
			LCD_PutString( 0, 4, "����__���__����");	
		}

		if( DataTime[ 2 ] >= 0x16 && DataTime[ 2 ] < 0x17 )//�賿 22��00~23��00
		{
			LCD_PutString( 0, 4, "����__���__ҹ��");	
		}

		if( DataTime[ 2 ] >= 0x00 && DataTime[ 2 ] < 0x04 )////��ҹ 00��00~4��00 
		{
			LCD_PutString( 0, 4, "����__���__ҹ��");	
		}
	}







	



}
