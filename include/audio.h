#ifndef _AUDIO_H
#define _AUDIO_H

#include<stdio.h>

#define AUDIO_PLAY "madplay audio/%d.mp3 &"





extern int music_play(void);
extern int music_last(void);
extern int music_next(void);
extern int music_stop(void);
extern int music_continue(void);

#endif
