// For CS205, Portland State University (J. Li)

// Bubble sort in C (baseline version)

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

extern int * filearray;

/*
const int STRING = 4;

//Level 3 is first level to give me trouble, I tried previously to send as 1
//long int array; but does not fit with given arrays, so had to split in main.

// LEVEL 0-4
// Print an int array of size n
//
//void printArray(char* msg, int* a, int n)
//void printArray(char* msg, char* a, int n)
void printArray(char* msg, char** a, int n)
{
  printf("%s",msg);
  for (int i = 0; i < n; i++)
    printf("%s, ", a[i]);
    //printf("%d, ", a[i]);
  printf("\n");
}

// LEVEL 0-2, 4
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

//LEVEL 3 
// Swaps the values of 2 given memory addresses, alloc'd as chars
//
//void swap(int* a, int i, int j)
//void swap(char* a, int i, int j)
void swap(char * i, char * j)
{
    //printf("%s", "ENTER SWAP\ni: ");
    //printf("%c", *i, 
  if (*i != *j) 
  {
    char tmp = *i;
    *i = *j;
    *j = tmp;
  }
}

// LEVEL 0-2
// Bubble sort a range [low,high) of an int array
//
//void bsort(int* a, int low, int high)
//void bsort(char* a, int low, int high)
//void bsort(char* a, int low, int high)
{
  if (high - low > 1) 
    for (int i = low; i < high; i++)
      for (int j = i+1; j < high; j++) 
		if (a[i] > a[j])
		  swap(a, i, j);
}

// LEVEL 3
// String version of bubble sort, could have done pointer arithmetic to 
// take up less space, but I can actually comprehend this.
//
//Changes: row = i, limit acts as high, whereas high acts as # of rows, added
//         counter to help swap btw/n current row and next row, and j is
//         removed due to col/count making j obsolete.
//
void string_bsort(char** a, int low, int high)
{
    //printf("%s", "ENTER BSORT");
    char * pos1 = NULL;
    char * pos2 = NULL;
    if (high - low > 1) 
        for (int limit = (high * (STRING - 1)), count = 1; limit > low; --limit, count = 1)
            for (int row = low; row < high && count < limit; ++row)
                for (int col = 0; col < (STRING - 1) && count < limit; ++col, ++count) 
                {
                    if (col == 2)
                        pos2 = &(a[row + 1][0]);
                    else
                        pos2 = &(a[row][col + 1]);
                    pos1 = &(a[row][col]);
                    if (*pos1 > *pos2)
                        swap(pos1,pos2);
                }
}

// LEVEL 2-3
//int * initArray(int n)
//char * initArray(int n)
char ** initArray(int n)
{
    if (n <= 0) return NULL;
    int curr;
    int limit = n * STRING;
    

    //int * array = (int*)malloc(n * sizeof(int));
    //Level 3 Implementation 1:
    //int * array = (int*)malloc((limit) * sizeof(int*));
    //Level 3 Implementation 3:
    char ** array = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n ; ++i)
        array[i] = (char*)malloc(STRING * sizeof(char));

    for (int r = 0; r < n ; ++r)
    {
        for (int c = 0; c < (STRING - 1); ++c)
        {
            //srand(time(NULL) + ((r + c) * c));
            curr = ((rand() % 26) + 97);
            array[r][c] = (char)curr;
        }
        array[r][STRING-1] = '\0';
    }

    return array;
}

*/
void MSGreadArray(int choice)
{
    switch (choice)
    {
        case(0):
            printf("Could not locate file\n");
            break;
        case(1):
            printf("Could not open file\n");
            break;
        case(2):
            printf("File loaded\n");
            break;
        case(3):
            printf("Enter input file name: ");
            break;
    }
}
// LEVEL 4
int * readArray(char * fname, int * np)
{
    FILE *inX;
    inX = fopen(fname, "rb");

    if (inX == NULL)
    {
        MSGreadArray(0);
        exit(1);
    }
    
    fseek(inX, 0L, SEEK_END);
    int size = ftell(inX);
    int n = size/ sizeof(int);
    rewind(inX);

    int * filearray = (int*)malloc(n * sizeof(int));

    if (inX == NULL)
    {
        MSGreadArray(1);
        fclose(inX);
        exit(2);
    }

    fread(filearray,sizeof(int),n,inX);
    *np = n;
    fclose(inX);
    MSGreadArray(2);
    return filearray;
} 


/*
// LEVEL 0-4
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
*/

