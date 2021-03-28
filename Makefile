ACC = arm-linux-gcc
CC = gcc



all:
	$(CC) source/*.c -o x86main -I./include/ -pthread 

arm:
	$(ACC) source/*.c -o armmain -I./include/ -pthread 

