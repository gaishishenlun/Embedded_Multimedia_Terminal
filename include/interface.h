#ifndef _INTERFACE_H
#define _INTERFACE_H

//宏
#define MAIN_INTERFACE "images/%d.bmp"


//库文件
#include<stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>


//函数声明
extern int bmp_menu(const char *pathname);
extern int blank_menu(void);
extern int dianzixiangce(void);

//其他头文件
//用户自定义类型
//函数接口声明
#endif