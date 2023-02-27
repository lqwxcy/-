/*********************************************************** 
文件名称： 定义变量符号头文件
作 者：    LQW
版 本：    0.01
说 明：    
时间 ：    2012年12月12日20:21:31
修改记录：
总结 ：   	
***********************************************************/
#ifndef __CONFIG_H__
#define __CONFIG_H__
#include<reg52.h>
#include<string.h>

typedef signed char S8;
typedef signed int S16;
typedef signed long S32;
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
typedef volatile signed char vS8;
typedef volatile signed int vS16;
typedef volatile signed long vS32;
typedef volatile unsigned char vu8;
typedef volatile unsigned int vu16;
typedef volatile unsigned long vu32;
typedef const u8 FLASH;
typedef enum{FALSE=0,TRUE=!FALSE} BOOL;

#endif
