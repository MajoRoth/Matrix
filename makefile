matrix: mat.o mymat.o
	gcc -g mat.o mymat.o -o matrix

mat.o: mat.c mat.h
	gcc -c mat.c -Wall -ansi -pedantic -o mat.o

mymat.o: mymat.c mat.h
	gcc -c mymat.c -Wall -ansi -pedantic -o mymat.o