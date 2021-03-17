-C Lab2_2/
CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = -lm
OBJ = Lab2_1.c
OBJ_TEST = Lab2_1.c Lab2_1_Test.c

Lab2_1: $(OBJ)
#	$(MAKE) -C subdir
	$(CC) $(CFLAGS) $(OBJ) -o Lab1_2
Lab2_1_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab2_1_Test -Dmain=_main $(LIBS)

.PHONY: clean
clean:
	del *.exe
