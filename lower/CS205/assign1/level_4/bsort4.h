// For CS205, Portland State University (J. Li)

// header file for bsort1.c

//
extern int * filearray;

//extern void printArray(char*, int*, int);
//extern void printArray(char*, char*, int);
//extern void printArray(char*, char**, int);
extern void printArray(char*, int*, int);

//extern void bsort(int*, int, int);
//extern void bsort(char*, int, int);
//extern void string_bsort(char**, int, int);
extern void bsort(int*, int, int);

//extern int * initArray(int n);
//extern char * initArray(int n);
//extern char ** initArray(int n);
extern int * initArray(int n);

extern int * readArray(char * fname, int * np);

extern void MSGinitArray(int choice);

extern void MSGreadArray(int choice);


