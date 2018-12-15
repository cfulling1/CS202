#include<stdio.h>
#include<stdlib.h>

int binarySearch(int key, int array[], int n);
void selectionSort(int array[], int n);

#define ARRAYSIZE  256

int main(int argc, char *argv[]) {
  int space,i;
  int j=0;
  int *arrayOne;
  int *arrayTwo;
  int *arrayThree;
  int a,b,c;

  if(argc!=2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 0;
  }

  FILE *fp = fopen(argv[1], "r");
  if(!fp) {
    fprintf(stderr, "Could not open %s\n", argv[1]);
    return 0;
  }

  space=ARRAYSIZE; 
  arrayOne=malloc(space * sizeof(int));
  arrayTwo=malloc(space * sizeof(int));
  arrayThree=malloc(space * sizeof(int));

  while(3==fscanf(fp, "%d %d %d", &a, &b, &c)) { //storing column contents in the 2 arrays
    if(j>=space) {
      space*=2;
      arrayOne=realloc(arrayOne, space * sizeof(int));
      arrayTwo=realloc(arrayTwo, space * sizeof(int));
      arrayThree=realloc(arrayThree, space * sizeof(int));
    }
    arrayOne[j]=a;
    arrayTwo[j]=b;
    arrayThree[j]=c;
    j++;
  }
  //selectionSort(arrayOne, j);
  selectionSort(arrayOne, j);

  for(i=0; i<=j; i++) {
    if((binarySearch(arrayTwo[i], arrayOne, j)) && (binarySearch(arrayThree[i], arrayOne, j))) printf("%d\n", arrayThree[i]);
  }
  fclose(fp);
}

int binarySearch(int key, int array[], int n) {
  int low, mid, high;
  low=0;
  high=n-1;

  while(low<=high) {
    mid=(low+high)/2;
    if(key==array[mid])  return 1;
    if(key<array[mid]) high=mid-1;
    else  low=mid+1;
  }
  return 0;
}

void selectionSort(int array[], int n) {
  int i, j, k;
  int min;
  int where;

  for(i=0; i<n-1; i++) {
    min=array[i];
    where=i;
    for(j=i+1; j<n; j++)
      if(array[j]<min) {
        min=array[j];
        where=j;
      }
    if(i!=where) {
      array[where]=array[i];
      array[i]=min;
    }
  }
}
