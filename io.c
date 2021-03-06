#include <stdlib.h>
#include <stdio.h> 	/* for printf */
#include <string.h>	/* for strlen */
#include <stdbool.h>

#include "regex.h"
#include "io.h"

void readStdIn(Array *lines)
{
	char *line = NULL;
	size_t size;

	while (getline(&line, &size, stdin) != -1) {
		insertArray(lines, line);
		line = NULL;
	}
}

void dummyString(Array *lines)
{
	insertArray(lines, "Fuelpipline.py");
	insertArray(lines, "ftuels.bag");
	insertArray(lines, "storePos.csv");
	insertArray(lines, "test2.png");
	insertArray(lines, "test.png");
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
	for(int i = 0; i < a->size; i++){
		if (a->array[i] != NULL)printf("%s", a->array[i]);
	}
}

void grepCheck(Array *a, char* search) {
	for (int i = 0; i < a->size; i++)
	{
		// Replace true with ALEX_MAGIC_FUNCTION(lines[i], search)
		if(a->array[i] == NULL) break;
		if(callRegex(search, a->array[i])) printf("%s\n", a->array[i]);
	}
}

