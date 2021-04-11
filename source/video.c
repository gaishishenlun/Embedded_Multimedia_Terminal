#include"video.h"

char cmd[50] = {0};
static short j = 0;


int video_play(void) {
	sprintf(cmd, VIDEO_PLAY, j);
	printf("%s\n",cmd);
	system(cmd);
	printf("%s\n",cmd);
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
	return 0;
}


int video_next(void) {
	if (j == 3)
		j = 0;
	else
		j++;
	return 0;
}


int video_kill(void) {
	system("killall -9 mplayer");
	return 0;
}
