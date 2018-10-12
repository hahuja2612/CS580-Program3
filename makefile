All: output
	valgrind ./output
output: program3.o hidden.o bomb.o
		gcc -g program3.o hidden.o bomb.o -o output
program3.o:program3.c
		gcc -g -c program3.c
bomb.o:bomb.c
		gcc -g -c bomb.c

		
