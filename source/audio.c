#include"audio.h"

char buf[50] = {0};
int i = 0;


int music_play(void) {
	sprintf(buf, AUDIO_PLAY, i);
	system(buf);
	return 0;
}


int music_stop(void) {
	system("killall -19 madplay");
	return 0;
}


int music_continue(void) {
	system("killall -18 madplay");
	return 0;
}


int music_last(void) {
	if (i == 0)
		i = 3;
	else
		i--;
	music_kill();
	music_play();
	return 0;
}


int music_next(void) {
	if (i == 3)
		i = 0;
	else
		i++;
	music_kill();
	music_play();
	return 0;
}


int music_kill(void) {
	system("killall -9 madplay");
	return 0;
}


int music_screen(void) {
	
}
