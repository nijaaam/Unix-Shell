CC=gcc
CFLAGS=-I.

run: main.o execute.o shell.o profile.o  
	gcc -o run main.o execute.o profile.o shell.o -lm 
