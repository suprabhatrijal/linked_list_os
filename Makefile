# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>
main: main.c list.c
	gcc -o main main.c list.c -I.
