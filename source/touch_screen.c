#include"touch_screen.h"

int fd_event0;


int open_ts(void) {
	fd_event0 = open("/dev/input/event0", O_RDONLY);
	if (-1 == fd_event0) {
		perror("Open /dev/intpu/event0 error!\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}


int read_ts(unsigned short *px, unsigned short *py) {
	struct input_event SIevent;
	while(1){
		printf("wait input_event!\n");
		if (-1 == read(fd_event0, &SIevent, sizeof(SIevent))) {
			perror("Read File Error!\n");
			return -1;
		}
		
		if(SIevent.type == EV_ABS && SIevent.code == ABS_X && SIevent.value > 0 && SIevent.value < 800) {
			*px = SIevent.value;
		}
		if(SIevent.type == EV_ABS && SIevent.code == ABS_Y && SIevent.value > 0 && SIevent.value < 480) {
			*py = SIevent.value;
		}

		if(SIevent.type == EV_KEY && SIevent.code == BTN_TOUCH && SIevent.value == 0) {
			break;
		}
		printf("read_in_OK (%d, %d)\n", *px, *py);
	}
	return 0;
}


int close_ts(void) {
	close(fd_event0);
	return 0;
}
