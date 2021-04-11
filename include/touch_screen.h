#ifndef _TOUCH_SCREEN_H
#define _TOUCH_SCREEN_H



#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

// input.h
#include<sys/time.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<linux/types.h>
#include<linux/input.h>

extern int open_ts(void);
extern int read_ts(unsigned short *x, unsigned short *y);
extern int close_ts(void);


#endif
