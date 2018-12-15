
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  CHUNK         4
#define  BUFFLEN    1024

void sortbylength(char *li[], int n);

int main() {
   char **lines;
   char buffer[BUFFLEN];
   int size;
   int nlines, len;
   int i;
   lines=malloc(CHUNK * sizeof(char *));
   size=CHUNK;
   nlines=0;
   while(fgets(buffer, BUFFLEN, stdin) != NULL) {
      if(nlines >= size) {
         size += CHUNK;
         lines=realloc(lines, size * sizeof(char *));
         fprintf(stderr,"reallocating from %d to %d\n", nlines, size);
      }
      len=strlen(buffer)-1;
      buffer[len]=0;
      lines[nlines++]=strdup(buffer);
   }
   sortbylength(lines,nlines);
   for(i=0;i<nlines;i++)
      printf("%s\n", lines[i]);
}
void sortbylength(char *li[], int n) {
   int i, j, where, min;
   char *tmps;
   int tmpp;
   int len[n];

   for(i=0; i<n; i++)
      len[i]=strlen(li[i]);
   for(i=0; i<n-1; i++) {
      where=i;
      min=len[i];
      for(j=i+1; j<n; j++) {
         if(len[j]<min) {
           where=j;
           min=len[j];
         }
      }
      if(where!=i) {
         tmps=li[i];
         li[i]=li[where];
         li[where]=tmps;

         tmpp=len[i];
         len[i]=len[where];
         len[where]=tmpp;
      }
   }
}

