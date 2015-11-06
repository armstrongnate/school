all:	babbler

babbler:	main.c
		gcc -std=c99 -m64 -Os -lm main.c `pkg-config lua5.2 --cflags --libs` -o babbler
