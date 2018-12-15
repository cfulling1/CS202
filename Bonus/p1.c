#include <stdio.h> 
#include <stdlib.h> 
#define K 1024

int main (int argc, char **argv){
  char buffer[K];
  char buffer1[K];
  if ( argc < 3){
    fprintf(stderr,"usage: %s file1 file2\n",argv[0]);
    exit(1);
  }
  FILE * fp=fopen(argv[1],"r");
  if(fp<0){
    fprintf(stderr,"could not open the file1\n");
    exit(1);
  }

  FILE * fp1=fopen(argv[2],"r");
  if(fp1<0){
    fprintf(stderr,"could not opent file2\n");
  }
  while(((fgets(buffer,K,fp)!=NULL) && (fgets(buffer1,K,fp1)!=NULL)) || ((fgets(buffer,K,fp)!=NULL)|| (fgets(buffer1,K,fp1))!=NULL)){
    if(feof(fp))
      printf("%s",buffer1);
    else if (feof(fp1))
      printf("%s",buffer);
    else {
      printf("%s",buffer);
      printf("%s",buffer1);
    }
  }
}
