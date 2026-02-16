// For CS205, Portland State University (J. Li)

// Driver for testing bsort
// 
#include "bsort3.h"
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));
    //Level 0
    /*
    int array[8] = {1,3,5,2,9,6,7,5};
    printArray("Init:  ", array, 8);
    bsort(array, 0, 8);
    printArray("Sorted: ", array, 8);
    */

    //Level 1,2,3
    int n;
    //int * array = NULL;
    //int * array = NULL;
    char ** array;
    do
    {
        MSGinitArray(0);
        scanf("%d", &n);
        array = initArray(n);
        if (array == NULL) MSGinitArray(1);
    } while (array == NULL);


    printArray("Init: ", array, n);
    string_bsort(array, 0, n);
    printArray("Sorted: ", array, n);
    return 0;
}
