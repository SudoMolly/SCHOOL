# Makefile for CS 205 assign4
#
dotprod: vector.o dotprod.o dotprod_asm.s
	gcc -o dotprod vector.o dotprod.o dotprod_asm.s

vector.o: vector.c vector.h

dotprod.o: dotprod.c vector.h 

clean:
	rm *.o dotprod
