#include<stdio.h>
#define   DATAFILE   "data"

int main() {
  FILE *fd;
  int n, sum;
  
  fd=fopen(DATAFILE, "r");
  if(fd == NULL) {
    fprintf(stderr, "unable to open %s\n", DATAFILE);
    return 0;
  }
  sum=0;
  while(fscanf(fd, "%d", &n) == 1)
    sum += n;
  fclose(fd);
  printf("%d\n", sum);
}
