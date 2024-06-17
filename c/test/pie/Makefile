CC=gcc
PIE_OPTION= -fpie -pie
CFLAGS= -g

pie:
	$(CC) $(PIE_OPTION) -o pie_open pie_test.c

nopie:
	$(CC) $(PIE_OPTION) -o pie_close pie_test.c
