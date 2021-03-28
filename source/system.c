#include "interface.h"
int bmp_menu();





int main(int argc, char *argv[])
{
    printf("Start!\n");
    int i;
    char *photo_file[6] = {
        "images/1.bmp",
        "images/2.bmp",
        "images/3.bmp",
        "images/4.bmp",
        "images/5.bmp",
        "images/6.bmp"
    };
    for (i = 0; i< 6; i++) {
        bmp_menu(photo_file[i]);
        sleep(2);
    }
    blank_menu();
    printf("End!\n");
	return 0;
}
