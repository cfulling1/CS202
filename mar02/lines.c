#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define K   1024

typedef struct node {
   char *word;
   struct node *link;
} NODE;

NODE *makenode(char b[]);
NODE *makelist(char *filename);
NODE *deletecommand(NODE *h, char *s);
NODE *deletenode(NODE *h, int key);
void printlist(NODE *h);
void rewritefile(char *filename, NODE *h);

int main(int argc, char *argv[]) {
   NODE *head;
   NODE *tail;
   NODE *p;
   char word[K];
   char cmd[K];

   head = NULL;
   head=makelist(argv[1]);
   if(head==NULL) return 0;
   for(;;) {
    printlist(head);
    printf("\n? ");
    fgets(cmd, K, stdin);
    switch(cmd[0]) {
      case 'd':
        head=deletecommand(head, cmd+1);
        break;
      case 's':
        rewritefile(argv[1], head);
        return 0;
      default:
        fprintf(stderr, "invalid command: %d\n", cmd[0]);
    }
   }
   while(fgets(word,K,stdin) != NULL){
      if(head == NULL){
         head = tail = makenode(word);
      } else {
         p = makenode(word);
         tail->link = p;
         tail = tail->link;
      }
   }
   for(p = head ; p != NULL ; p = p->link)
      printf("%s", p->word);
   deletelist(head);
   head = NULL;

}
NODE *makenode(char b[K])
{
   NODE *tmp;

   tmp = malloc(sizeof(NODE));
   tmp->word = strdup(b);
   return tmp;
}

NODE *makelist(char *filename) {
  NODE *head, *tail;
  char word[K];
  FILE *fd=fopen(filename, "r");
  if(fd==NULL) {
    fprintf(stderr, "unable to open %s\n", filename);
    return NULL;
  }
  head=NULL;
  while(fscanf(fd,"%s", &word)==1) {
    if(head==NULL) {
      head=tail=makenode(word);
    }
    else {
      tail->link=makenode(word);
      tail=tail->link;
    }
  }
  fclose(fd);
  return head;
}

NODE *deletecommand(NODE *h, char *s) {
  int key;

  while(*s==' ')  s++;
  if(!isdigit(*s)) {
    fprintf(stderr, "usage: d number\n");
    return h;
  }
  key=atoi(s);
  return deletenode(h, key);
}

NODE *deletenode(NODE *h, int key) {
  NODE *p, *q;
  int i=1;
  if(h==NULL) return h;

  if(key==1) {
    p=h;
    h=h->link;
    free(p);
    return h;
  }

  for(p=h; p->link != NULL; p=p->link) {
    i++;
    q=p->link;

    if(q==NULL) break;

    if(i==key) {
      p->link = q->link;
      free(q);
      break;
    }
  }
  return h;
}

void printlist(NODE *h) {
  NODE *p;
  int length=0;
    for(p=h; p!=NULL; p=p->link) {
      length++;
      printf("%d %s\n", length, p->word);
    }
}

void rewritefile(char *filename, NODE *h) {
  FILE *fp = fopen(filename, "w");
  
  NODE *p;
  for(p=h; p!=NULL; p=p->link) {
    fprintf(fp, "%s\n", p->word);
  }
}
