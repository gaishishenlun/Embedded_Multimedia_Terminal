#include"interface.h"


int bmp_menu(const char *pathname) {
    // 普通文件用标准I/O流打开
    FILE *fp_bmp = NULL;
    fp_bmp = fopen(pathname, "r");
    printf("%s 打开文件成功!\n", pathname);
    
    // 设备文件用系统I/O流
    int fd_fb0 = 0;
    fd_fb0 = open("/dev/fb0", O_RDWR);
    if (-1 == fd_fb0) {
        perror("打开/dev/fb0失败!\n");
        return -1;
    }

    fseek(fp_bmp, 54, SEEK_SET);

    char bmp_buffer[800*480*3] = {0};
    fread(bmp_buffer, sizeof(bmp_buffer), 1, fp_bmp);
    if(0 != ferror(fp_bmp)) {
		perror("图片数据读取错误\n");
		return -1;
	}

    // 格式转换
    int i = 0;
	char A = 0x00;
	int lcd_buffer[800*480] = {0};
	for(i=0; i<800*480; i++)
		lcd_buffer[i] = bmp_buffer[i*3]<<0 | bmp_buffer[i*3+1]<<8 | bmp_buffer[i*3+2]<<16 | A<<24;    

    // 地址映射
    int *p_mmap = NULL;
	p_mmap = (int *)mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, fd_fb0, 0);
	if(MAP_FAILED == p_mmap) {
		perror("映射失败:");
		return -1;
	}
    else {}

	int *p_mmap_usr = p_mmap;
	int x=0, y=0;
	for(y=0; y<480; y++) {
		for(x=0; x<800; x++)
			*(p_mmap_usr+800*(480-1-y)+x) = lcd_buffer[800*y+x];
	}
    
    // 释放资源
    close(fd_fb0);
    fclose(fp_bmp);
    munmap(p_mmap, 800 * 480 * 4);
    p_mmap = NULL; 
    p_mmap_usr = NULL;
    fp_bmp = NULL;
    return 0;
}

int blank_menu(void) {
    int fd_fb0 = 0;

    fd_fb0 = open("/dev/fb0", O_RDWR);
    if (-1 == fd_fb0) {
        perror("打开/dev/fb0失败!\n");
    }
    else {}

    int *p_mmap = NULL;
	p_mmap = (int *)mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, fd_fb0, 0);
	if(MAP_FAILED == p_mmap) {
		perror("映射失败:");
		return -1;
	}
    else {}

    int *p_mmap_usr = p_mmap;
    p_mmap = NULL;
    int i;
    for (i = 0; i< 800 * 480; i++) {
        *(p_mmap_usr + i) = 0x00000000;
    }
    
    close(fd_fb0);
    munmap(p_mmap_usr, 800 * 480 * 4);
    p_mmap_usr = NULL;

    return 0;
}