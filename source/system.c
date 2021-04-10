#include "interface.h"
#include "touch_screen.h"


int main(int argc, char *argv[])
{
	unsigned short usx = 0, usy = 0;

	// 显示主界面
	bmp_menu("images/main.bmp");

#if 0
	dianzixiangce();	// 打开电子相册
	blank_menu();			// 黑屏
#endif
	// 1、打开工业液晶屏做输出 /dev/input/event0
	open_ts();

	// 2、读取屏幕输入
	while (1) {
		read_ts(&usx, &usy);
		//if (read_ts(&usx, &usy))
		printf("(%d, %d)\n",usx, usy);

		if (usy > 280 && usy < 350) {

			if (usx > 140 && usx < 220) {
				printf("音乐播放器\n");
			}

			if (usx > 360 && usx < 440) {
				printf("电子相册\n");
			}

			if (usx > 570 && usx < 640) {
				printf("视频播放器\n");
			}
		}
	}



	// 3、关闭屏幕输入
	close_ts();
	return 0;
}
