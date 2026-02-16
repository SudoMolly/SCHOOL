// For CS205, Portland State University (J. Li)

// Bubble sort in C (baseline version)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>

// Print an int array of size n
//
//void printArray(char* msg, int* a, int n)
void printArray(char* msg, char* a, int n)
{
  printf(msg);
  for (int i = 0; i < n; i++)
    printf("%c, ", a[i]);
    //printf("%d, ", a[i]);
  printf("\n");
}

// Swap two int array elements
//
//void swap(int* a, int i, int j)
void swap(char* a, int i, int j)
{
  if (i != j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
}

// Bubble sort a range [low,high) of an int array
//
//void bsort(int* a, int low, int high)
void bsort(char* a, int low, int high)
{
  if (high - low > 1) 
    for (int i = low; i < high; i++)
      for (int j = i+1; j < high; j++) 
		if (a[i] > a[j])
		  swap(a, i, j);
}

//int * initArray(int n)
char * initArray(int n)
{
    if (n <= 0) return NULL;
    ++n;
    int curr;

    //int * array = (int*)malloc(n * sizeof(int));
    char * array = (char*)malloc(n * sizeof(char));
    
    for (int i = 0; i < n-1; ++i)
    {
        srand(time(NULL) + i);
        curr = ((rand() % 26) + 97);
        array[i] = (char)curr;
    }
    array[n-1] = '\0';

    return array;
}

void MSGinitArray(int choice)
{
    switch (choice)
    {
        //Intialize array
        case (0):
        {
            printf("\nEnter array size: ");
            break;
        }

        //Error code
        case (1):
        {
            printf("n must be a positive integer\n");
            break;
        }
    }
}




