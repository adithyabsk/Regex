#ifndef IO_H
#define IO_H

typedef struct {
  char **array;
  size_t used;
  size_t size;
} Array;

char** searchFiles(char** dir, bool recurse);
char** readFiles(char** dir);
void readStdIn(Array *lines);
void dummyString(Array *lines);

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, char* element);
void freeArray(Array *a);
void printArray(Array *a);
void grepCheck(Array *a, char* search);

#endif