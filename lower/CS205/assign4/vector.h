// For CS 205 W'24 (JL)

// data structure for vectors
//
typedef double data_t;  
typedef struct _vec {
  size_t len;
  data_t *data;
} *vec_ptr;

// utility functions
//
vec_ptr vec_alloc(size_t len);
vec_ptr random_vec(size_t len);
void print_vec(vec_ptr v, int bound);
