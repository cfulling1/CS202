#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int i,j,m,n,ncols;

  if(argc != 4){
    fprintf(stderr,"usage: %s count maxnumber columns\n", argv[0]);
    exit(0);
  }
  srandom(getpid());   // restart the random number generator
  n = atoi(argv[1]);
  m = atoi(argv[2]);
  ncols = atoi(argv[3]);
  for(i=0;i<n;i++){
    for(j=0;j<ncols;j++)
      printf("%9d", random() % 100);
    printf("\n");
  }
}
