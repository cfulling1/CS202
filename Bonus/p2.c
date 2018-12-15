#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define K 1024

int main (int argc, char **argv){
  char buffer[K];
  if ( argc < 2){
    fprintf(stderr,"usage: %s file\n",argv[0]);
    exit(1);
  }
  FILE * fp=fopen(argv[1],"r");
  if(fp<0){
    fprintf(stderr,"could not open the file1\n");
    exit(1);
  }
  while(fgets(buffer,K,fp)!=NULL) {
    if(buffer[0]>='A' && buffer[0]<='Z') {
      if(strlen(buffer)>30) {
        if(buffer[strlen(buffer)-2]=='.' || buffer[strlen(buffer)-2]=='!')
          printf("%s", buffer);
      }
    }
  }
}
