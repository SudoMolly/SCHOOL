.PHONY	: all clean

CC = gcc -O -z noexecstack

all	: task1 task2 task3 task4 task5 task6 task7
	./task1 "Length of Array"
	./task2 "Largest Number in Array"
	./task3 "Sum of Numbers in Array"
	./task4 "Position of Largest Number in Array"
	./task5 "Average of Numbers in Array"
	./task6 "Reverse Numbers in Array"
	./task7 "Sort Numbers in Array"

task1: task1.s main.c
	$(CC) -o task1 main.c task1.s

task2: task2.s main.c
	$(CC) -o task2 main.c task2.s

task3: task3.s main.c
	$(CC) -o task3 main.c task3.s

task4: task4.s main.c
	$(CC) -o task4 main.c task4.s

task5: task5.s main.c
	$(CC) -o task5 main.c task5.s

task6: task6.s main.c
	$(CC) -o task6 main.c task6.s

task7: task7.s main.c
	$(CC) -o task7 main.c task7.s

clean	:
	rm task1 task2 task3 task4 task5 task6 task7

