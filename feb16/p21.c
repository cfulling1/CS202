#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 256

int main(int argc, int *argv[]) {
  char file1[MAX];
  char file2[MAX];
  int compare=0;
  int *p1, *p2;
  
  if(argc<3) {
    fprintf(stderr, "Usage: %s source destination\n", argv[0]);
    exit(0);
  }

  FILE *fp = fopen(argv[1], "r");
  if(!fp) {
    fprintf(stderr, "Error: can't open %s for reading\n", argv[1]);
    exit(0);
  }

  FILE *sfp = fopen(argv[2], "r");
  if(!sfp) {
    fprintf(stderr, "Error: can't open %s for reading\n", argv[2]);
    exit(0);
  }

  while(1) {
    p1=fgets(file1, MAX, fp);
    p2=fgets(file2, MAX, sfp);
    
    compare=strcmp(file1, file2);
      if(compare!=0){
	      printf("%s%s", file1, file2);
	      fclose(fp);
	      fclose(sfp);
	      exit(0);
      }
      if(p1==NULL && p2==NULL)  return 0;
  }
}
