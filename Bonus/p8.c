#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define K 1024

typedef struct treenode1 {
char *firstname;
struct treenode1 *left, *right;
} TREENODE1;

typedef struct treenode2 {
char *lastname;
struct treenode2 *left, *right;
} TREENODE2;


TREENODE1 *makenode1(char firstname[K]);
TREENODE2 *makenode2(char lastname[K]);
void decorate1(TREENODE1 *tree, TREENODE1 *leaf);
void decorate2(TREENODE2 *tree, TREENODE2 *leaf);
void inorder1(TREENODE1 *tree);
void inorder2(TREENODE2 *tree);
void freetree1(TREENODE1 *tree);
void freetree2(TREENODE2 *tree);


int main() {
  TREENODE1 *root1;
  TREENODE1 *ptr1;

  TREENODE2 *root2;
  TREENODE2 *ptr2;

  root1, root2 = 0;

  char firstname[K];
  char lastname[K];

  char buffer[K];
  char *line;

  int i;

  FILE *fp = fopen("data", "r");
  if(fp<0) {
    fprintf(stderr, "could not open the name file\n");
    exit(0);
  }

  while(fgets(buffer,K,fp)!=NULL) {
    int count=0;
    line=strtok(buffer, " ");
    while(line!=NULL) {
      count++;
      if(count==1) strcpy(firstname,line);
      if(count==2) {
        line[strlen(line)-1]='\0';
	      strcpy(lastname,line);
	      if(root1 == NULL)  root1 = makenode1(firstname);
	      if(root2 == NULL)  root2 = makenode2(lastname);
	      else {
	        ptr1 = makenode1(firstname);
	        ptr2 = makenode2(lastname);
	        decorate1(root1,ptr1);
	        decorate2(root2,ptr2);
	      }
      }
     line=strtok(NULL," ");
    }
  }
  inorder1(root1);
  printf("\n");
  inorder2(root2);

  freetree1(root1);
  freetree2(root2);
}


TREENODE1 *makenode1(char firstname[K]) {
  TREENODE1 *p;
  p = malloc(sizeof(TREENODE1));

  p->firstname=malloc(sizeof(char)*K);
  strcpy(p->firstname, firstname);

  p->left = 0;
  p->right = 0;

  return p;
}

TREENODE2 *makenode2(char lastname[K]) {
  TREENODE2 *p;
  p=malloc(sizeof(TREENODE2));

  p->lastname=malloc(sizeof(char)*K);
  strcpy(p->lastname, lastname);

  p->left=0;
  p->right=0;

  return p;
}

void decorate1(TREENODE1 *tree, TREENODE1 *leaf) {
  for(;;) {
    if(strcmp(leaf->firstname,tree->firstname)<0) {
      if(tree->left == NULL) {
        tree->left = leaf;
        return;
      }
    tree = tree->left;
    }
    else {
      if(tree->right == NULL) {
        tree->right = leaf;
        return;
      }
    tree = tree->right;
    }
  }
}

void decorate2(TREENODE2 *tree, TREENODE2 *leaf) {
  for(;;) {
    if(strcmp(leaf->lastname, tree->lastname)<0) {
      if(tree->left == NULL) {
        tree->left = leaf;
        return;
      }
    tree = tree->left;
    }
    else {
      if(tree->right == NULL) {
        tree->right = leaf;
        return;
      }
    tree = tree->right;
    }
  }
}

void inorder1(TREENODE1 *tree) {
  if(tree!=NULL) {
    inorder1(tree->left);
    printf("%s\n", tree->firstname);
    inorder1(tree->right);
  }
}

void inorder2(TREENODE2 *tree) {
  if(tree!=NULL) {
    inorder2(tree->left);
    printf("%s\n", tree->lastname);
    inorder2(tree->right);
  }
}

void freetree1(TREENODE1 *tree) {
  if(tree!=NULL) {
    freetree1(tree->left);
    freetree1(tree->right);
    free(tree);
  }
}

void freetree2(TREENODE2 *tree) {
  if(tree!=NULL) {
    freetree2(tree->left);
    freetree2(tree->right);
    free(tree);
  }
}

/*
void realnamecase(char name[K], TREENODE *tree) {
  char *ptr;
  if(tree!=NULL) {
    realnamecase(name,tree->left);
    ptr=strcasestr(tree->realname,name);
    if(ptr) {
      printf("%s:", tree->login);
	    printf("%d:", tree->uid);
	    printf("%s\n", tree->realname);
    }
    realnamecase(name,tree->right);
  }
}

*/
