// For CS 205 W'24 (JL)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

// allocate memory for a vector
// 
vec_ptr vec_alloc(size_t len) 
{
  vec_ptr v = (vec_ptr) malloc(sizeof(struct _vec));
  v->data = (data_t *) malloc(sizeof(data_t) * len);
  v->len = len;
  return v;
}

// initialize a vector with random values in [1,2)
// 
vec_ptr random_vec(size_t len)
{
  vec_ptr v = vec_alloc(len);
  srand(time(NULL));
  for(int i = 0; i < len; ++i)
	v->data[i] = 1 + (double)rand()/(double)RAND_MAX;
  return v;
}

// print vector elements upto bound
// 
void print_vec(vec_ptr v, int bound) 
{
  if (v->len < bound)
	bound = v->len;
  for(int i = 0; i < bound; ++i)
	printf("%5.3f ", v->data[i]);
  printf("\n");
}
