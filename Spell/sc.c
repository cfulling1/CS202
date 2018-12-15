#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE (1)
#define CAPACITY (10)

typedef struct{
	char** dictionary;
	int used;
	int size;
} dynArray;

void initArray(dynArray* arr){
	arr->used = 0;
	arr->size = CAPACITY;
	arr->dictionary = (char**) malloc(arr->size * sizeof(char*));
	
	memset(arr->dictionary, 0, arr->size * sizeof(char*));
}

void insertItem(dynArray* arr, char* item){
	if (arr->used == arr->size){
		arr->size += SIZE;
		arr->dictionary = (char**) realloc(arr->dictionary, arr->size * sizeof(char*));
	}
	arr->dictionary[arr->used++] = item;
}

int findItem(dynArray* arr, char* item){
	for (int i = 0; i < arr->used; i++){
		if (!strcmp(arr->dictionary[i], item)){
			return i;
		}
	}
	return -1;
}

void freeArr(dynArray* arr){
	for (int i = 0; i < arr->used; i++)
		free(arr->dictionary[i]);

	arr->used = arr->size = 0;
	free(arr->dictionary);
	arr->dictionary = NULL;
}

char isPunctuation(char c){
	return c == ' ' || c == '\n' || c == '.' || c == ','|| c == ':' || c == ';' || c == EOF;
}

char* readWord(FILE* file){
	if (feof(file))
		return NULL;
  long pos = ftell(file);
  char c;
	do {
		c = fgetc(file);
	} 
	while (!isPunctuation(c));

	long length = ftell(file) - pos - 1;
	if (length <= 0)
		return NULL;

	char* word = (char*) malloc(length + 1);
	memset(word, 0, length + 1);
	fseek(file, pos, SEEK_SET);
	fread(word, sizeof(char), length, file);
	for (long i = 0; i < length; i++)
		word[i] = tolower(word[i]);
	fgetc(file);

	return word;
}

int main (int argc, char** argv) {
  FILE* dictFp = fopen("/usr/dict/words", "r");
  if (!dictFp) {
    printf("An error occured while opening the dictionary\n");
    fclose(dictFp);
    return 1;
  }
 
 	if (argc < 2) {
		printf("Run program again with file name\n");
		return 2;
	}
	
	FILE* fp = fopen(argv[1], "r");
	if (!fp) {
		printf("An error occured while opening file '%s'\n", argv[1]);
		return 1;
	}
	
	dynArray dict;
	initArray(&dict);
	char* curWord;
	while (curWord = readWord(dictFp)) {
		insertItem(&dict, curWord);
	}
  fclose(dictFp);
  dynArray read;
	initArray(&read);
	while (curWord = readWord(fp)) {
		if (findItem(&read, curWord) == -1 && findItem(&dict, curWord) == -1) {
			printf("%s\n", curWord);
		}
		insertItem(&read, curWord);
	}

	freeArr(&read);
  freeArr(&dict);
  fclose(fp);

	return 0;
}

