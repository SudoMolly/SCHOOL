// For CS205, Portland State University (J. Li)

// Driver for testing bsort
// 
#include "bsort0.h"

int main()
{
  int array[8] = {1,3,5,2,9,6,7,5};
  printArray("Init:  ", array, 8);
  bsort(array, 0, 8);
  printArray("Sorted: ", array, 8);
}
