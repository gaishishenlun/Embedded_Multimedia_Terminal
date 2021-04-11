#include"video.h"

char buuf[50] = {0};
int j = 0;


int video_play(void) {
	sprintf(buuf, VIDEO_PLAY, j);
	system(buuf);
	return 0;
}


int video_stop(void) {
        system("killall -19 mplayer");
        return 0;
}


int video_continue(void) {
        system("killall -18 mplayer");
        return 0;
}


int video_last(void) {
        if (j == 0)
                j = 3;
        else
                j--;
        video_kill();
        video_play();
        return 0;
}


int video_next(void) {
        if (j == 3)
                j = 0;
        else
                j++;
        video_kill();
        video_play();
        return 0;
}


int video_kill(void) {
        system("killall -9 mplayer");
        return 0;
}
