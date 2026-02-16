// For CS205, Portland State University (J. Li)

// Driver for testing bsort
// 
#include "bsort2.h"
#include <stddef.h>
#include <stdio.h>

int main()
{
    //Level 0
    /*
    int array[8] = {1,3,5,2,9,6,7,5};
    printArray("Init:  ", array, 8);
    bsort(array, 0, 8);
    printArray("Sorted: ", array, 8);
    */

    //Level 1
    int n;
    //int * array = NULL;
    char * array = NULL;
    do
    {
        MSGinitArray(0);
        scanf("%d", &n);
        array = initArray(n);
        if (array == NULL) MSGinitArray(1);
    } while (array == NULL);

    printArray("Init: ", array, n);
    bsort(array, 0, n);
    printArray("Sorted: ", array, n);
    return 0;
}
