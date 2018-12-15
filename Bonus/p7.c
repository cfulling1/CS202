#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *link;
} NODE;

int listlength(NODE *h);
NODE *makenode(int num);
void printlist(NODE *h);
NODE *rmnode(NODE *h);
NODE *rmodds(NODE *h);

int main() {
  NODE *head;        // head of the list, a pointer
  NODE *tail;        // tail of the list, a pointer
  NODE *p;           // p = pointer
  int n;

  FILE *fp = fopen("nums", "r");
  head = tail = 0;
  while(fscanf(fp, "%d", &n) == 1) {
    p = makenode(n);
    if(head == NULL || tail == NULL) {
      head = tail = p;
    }
    else {
      tail->link = p;
      tail = p;
    }
  }
  printlist(head);
  printf("list length: %d\n\n", listlength(head));

  p = rmnode(head);
  printlist(head);
  printf("new list length: %d\n\n", listlength(head));

  p = rmodds(head);
  printlist(head);
  printf("new list length: %d\n\n", listlength(head));
}

void printlist(NODE *h) {
  NODE *p;

  for(p = h ; p != NULL ; p = p->link)
     printf("%d\n", p->data);
}

NODE *makenode(int num) {
   NODE *p;

   p = malloc(sizeof(NODE));
   p->data = num;
   p->link = NULL;
   return p;
}

int listlength(NODE *h) {
  if(h==NULL) return 0;

  NODE *ptr;
  int count=1;

  for(ptr=h; ptr->link!=NULL; ptr=ptr->link)
    count++;

  return count;
}

NODE *rmnode(NODE *h) {
  NODE *ptr, *ptr2;

  if(h==NULL) return h;

  ptr2=h;
  ptr=h->link; //ahead
  while(ptr->link) {
    ptr=ptr->link;
    ptr2=ptr2->link;
  }
  free(ptr);
  ptr2->link=NULL;
  return h;
}

NODE *rmodds(NODE *h) {
  NODE *ptr=h; //ahead
//  NODE *prev=NULL;
  NODE *ptr2=h;

  if(h==NULL) return 0;

  if(ptr->link == NULL) {
    if((ptr->data % 2) != 0) return 0;
    else return h;
  }
  while(ptr2!=NULL && (ptr2->data % 2)!=0) {
    ptr = ptr2;
    ptr2 = ptr2->link;
    h=ptr2;
//    ptr->link=NULL;
    free(ptr);
  }
  while(ptr2) {
    if((ptr2->data % 2) != 0) {
      ptr->link = ptr2->link;
      free(ptr2);
      ptr2 = ptr->link;
    }
    else {
      ptr = ptr2;
      ptr2 = ptr2->link;
    }
  }
  return h;
}
