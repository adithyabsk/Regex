#include <stdlib.h>
#include <stdio.h> 	/* for printf */
#include <string.h>	/* for strlen */
#include <stdbool.h>

// Grep Wildcard functionality
// DataStructures Final: Dr. Morrison

// AUTHORS: Alexander Allen
//	       Adithya Balaji

// Change Log:
// 12:00pm 2-7-17: Initial Commit with base structure (Alexander)
// 3:30pm 2-7-17: Read from standard in, add to data structre is broken (Alexander & Adithya)

typedef struct {
  char **array;
  size_t used;
  size_t size;
} Array;

char** searchFiles(char** dir, bool recurse);
char** readFiles(char** dir);
void readStdIn(Array *lines);
char** wildcard(char **data, char *com, bool lines);

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, char* element);
void freeArray(Array *a);
void printArray(Array *a);

int main(int argc, char **argv)
{
	Array lines;
	initArray(&lines, 1);

	readStdIn(&lines);
	printArray(&lines);
	return 0;
}

char** searchFiles(char** dir, bool recurse)
{

}

char** readFiles(char** dir)
{

}

void readStdIn(Array *lines)
{
	char *line = NULL;
	size_t size;
	// char dst[100];

	while (getline(&line, &size, stdin) != -1) {
		insertArray(lines, line);
		line = NULL;
	}
}

char** wildcard(char **data, char *com, bool lines)
{

}

void initArray(Array *a, size_t initialSize) {
	a->array = (char **)malloc(initialSize * sizeof(char) * 100);
	a->used = 0;
	a->size = initialSize;
}

void insertArray(Array *a, char* element) {
	// a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
	// Therefore a->used can go up to a->size 
	// printf("%s", element);
	if (a->used == a->size) {
		a->size *= 2;
		a->array = (char **)realloc(a->array, a->size * sizeof(char) * 100);
	}
	a->array[a->used++] = element;
}

void freeArray(Array *a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}

void printArray(Array *a) {
	for(int i=0; i<a->size; i++){
		if (a->array[i] != NULL)printf("%s", a->array[i]);
	}
}