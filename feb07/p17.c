#include<stdio.h>

int countLines();

int main(int argc, char* argv[]) {
  int count1, count2;
  
  if(argc<3) {
    fprintf(stderr, "Error\n");
    return 0;
  }
  
  FILE *fp = fopen(argv[1],"r");
  if(!fp) {
    fprintf(stderr, "Error: your file %s could not be opened\n", argv[1]);
    return 1;
  }
  FILE *sfp = fopen(argv[2], "r");
  if(!fp) {
    fprintf(stderr, "Error: your file %s could not be opened\n", argv[2]);
    return 1;
  }

  count1=countLines(fp);
  count2=countLines(sfp);

  if(count1>=count2)  printf("%s\n", argv[1]);
  else  printf("%s\n", argv[2]);
}

int countLines(FILE *name) {
  int count=0;
  char ch;
  ch=getc(name);
  while(ch!=EOF) {
    if(ch=='\n') {
      count++;
      ch=getc(name);
    }
    else {
     ch=getc(name);
   }
  }
  return count;
}
