main: main.c parsexe.c parsexec.h
	cc main.c parsexe.c -o main -Wall -Wextra -pedantic -std=c99
