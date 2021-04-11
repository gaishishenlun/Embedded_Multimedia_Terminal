#include"interface.h"
#include"touch_screen.h"


int main(int argc, char *argv[])
{
	unsigned short usx = 0, usy = 0;
	int flag = 0;
	// 显示主界面
	bmp_menu("images/main.bmp");

	// 1、打开工业液晶屏做输出 /dev/input/event0
	open_ts();

	// 2、读取屏幕输入
	while (1) {
		read_ts(&usx, &usy);
		//if (read_ts(&usx, &usy))
		printf("(%d, %d)\n",usx, usy);

		if (usy > 280 && usy < 350) {
			//音乐播放器
			if (usx > 140 && usx < 220) {
				bmp_menu("images/music.bmp");
				music_play();
				flag = 1;
				while(1) {
					read_ts(&usx, &usy);
					if (usy > 380 && usy < 440) {
						if (usx > 385 && usx < 450) {
							if (flag == 1) {
								music_stop();
								bmp_menu("images/stop.bmp");
								flag = 2;
							}
							else if (flag == 2) {
								music_continue();
								bmp_menu("images/music.bmp");
								flag = 1;
							}
						}

						if (usx > 165 && usx < 235) {
							music_last();
							bmp_menu("images/music.bmp");
						}

						if (usx > 595 && usx < 660) {
							music_next();
							bmp_menu("images/music.bmp");
						}
					}
					if (usx > 300 && usx < 535 && usy > 30 && usy < 260) {
						music_kill();
						bmp_menu("images/main.bmp");
						sleep(1);
						break;
					}
				}
				continue;
			}

			// 电子相册
			if (usx > 360 && usx < 440) {
				dianzixiangce();	// 打开电子相册
				blank_menu();			// 黑屏
				sleep(2);
				bmp_menu("images/main.bmp");
			}

			// 视频播放器
			if (usx > 570 && usx < 640) {
				// 播放音乐
				video_play();
				while(1) {
					if (usy < 240) {
						if (usx > 600) {
							// 下一曲
						}

						if (usx < 200) {
							// 上一曲
						}
					}
					else {

					}
				}

				printf("视频播放器\n");
			}
		}
	}



	// 3、关闭屏幕输入
	close_ts();
	return 0;
}
