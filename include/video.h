#ifndef _VIDEO_H
#define _VIDEO_H

#include"stdio.h"

//#define VIDEO_PLAY "mplayer -slave -quiet video_file/%d.avi -zoom -x 760 -y 480 >/tmp/mplayer.log 2>&1 &"
#define VIDEO_PLAY "mplayer video_file/%d.avi -zoom -x 760 -y 480 &"


extern int video_play(void);
extern int video_last(void);
extern int video_next(void);
extern int video_stop(void);
extern int video_continue(void);

#endif
