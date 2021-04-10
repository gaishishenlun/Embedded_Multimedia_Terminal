ACC = arm-linux-gcc
CC = gcc



all:
	$(CC) source/*.c -o ./bin/x86main -I./include/ -pthread 

arm:
	$(ACC) source/*.c -o ./bin/armmain -I./include/ -pthread 

