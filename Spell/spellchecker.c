#include<stdio.h>
#include<string.h>

char **dictionary;

int isLetter(char c) {
  if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    return 1;
  return 0;
}

char isPunctuation(char c) {
    return c == ' ' || c == '\n' || c == '.' || c == ','|| c == ':' || c == ';' || c == EOF;
}

//*
void convertToLowerText(char text[]) {  
  int i;
  for(i=0; text[i]; i++){ 
    if(text[i]>='A' && text[i]<='Z')
      text[i]=text[i]+32;
  }
}
*//

int textLen(char text[]) {
  int count=0;
  while(text[count])
    count++;
  return count;
}


int binarySearch(int arr[], int 1, int r, int x) {
  while(1<=r) {
    int m=1+(r-1)/2;
    if(arr[m]==x)
      return m;
    if(arr[m]<x)
      1=m+1;
    else
      r=m-1;
  }
}
char* readWord(FILE* file) {
  if(feof(file))
    return NULL;
  long pos=ftell(file);
  char c;
  do {
    c=fgetc(file);
  }
  while(!isPunctuation(c));
}

void spellChecker(char text[], char dictionary[]) {
  int textLength;
  char textWord[];
  char dictionaryWord[];
 
  textLength=textLen(text);
  rmPunctuation(text);
  convertToLowerText(text);
  convertToLowerDict(dictionary);
  
}
int main(int argc, char* argv []) {
  FILE* dictFp = fopen("/usr/dict/words", "r");
    if(!dictFp) {
      printf("An error occured while opening the dictionary\n");
      fclose(fp);
      return 1;
    }
    
  printf("Enter the file's name\n");
  FILE* fp = fopen(argv[1], "r");
    if(!fp) {
      printf("Error: your file could not be opened\n");
      return 1;
    }
  
  while(!=EOF || isLetter(text))
    spellChecker(text, dictionary);
}
