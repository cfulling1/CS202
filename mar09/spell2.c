/*
to print dictionary in ascending order, just swap out "preorder" in line 76 for "inorder"
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define K 1024

typedef struct treenode {
  char *word;
  struct treenode *left, *right;
} TREENODE;

TREENODE *makenode(char b[K]);
void decorate(TREENODE *tree, TREENODE *leaf);
void preorder(FILE *dfd, TREENODE *tree);
void inorder(FILE *dfd, TREENODE *tree);
int find(char key[K], TREENODE *tree);
void freetree(TREENODE *tree);

int main(int argc, char *argv[]) {
  TREENODE *root;
  TREENODE *ptr;

  char x[K];
  char key[K];
  char cmd[K];

  if(argc<2) {
    fprintf(stderr, "error: usage %d\n", argc);
    return 0;
  }

  FILE *fd = fopen(argv[1],"r");
  FILE *dfd = fopen("unsorteddict", "r");

  if(fd == NULL){
    fprintf(stderr,"unable to open %s\n", argv[1]);
    return 0;
  }

  if(dfd == NULL){
    fprintf(stderr,"unable to open the dictionary\n");
    return 0;
  }

  root = 0;
  while(fscanf(dfd,"%s", &x) == 1) {
    if(root == NULL){
      root = makenode(x);
    }
    else {
      ptr = makenode(x);
      decorate(root,ptr);
    }
  }

  while(fscanf(fd,"%s",key)==1) {
    if(find(key, root)!=1) {
      printf("Is '%s' really mispelled? (y or n): ", &key); 
      fgets(cmd,K,stdin);
      switch(cmd[0]) {
        case 'y': break;
        case 'n':
          ptr=makenode(key);
          decorate(root,ptr);
          break;
        default: fprintf(stderr, "invalid command: %d\n", cmd[0]);
      }
    }
  }

  fclose(fd);
  fclose(dfd);
  dfd=fopen("unsorteddict", "w");
  preorder(dfd,root);
  freetree(root);
}

TREENODE *makenode(char b[K]) {
  TREENODE *p;

  p = malloc(sizeof(TREENODE));
  p->word=malloc(sizeof(char)*K);
  strcpy(p->word, b);
  p->left = p->right = 0;
  return p;
}

void decorate(TREENODE *tree, TREENODE *leaf) {
  for(;;){
    if(strcmp(leaf->word,tree->word)<0){
      if(tree->left == NULL){
        tree->left = leaf;
        return;
      }
      tree = tree->left;
    }
    else {
      if(tree->right == NULL){
        tree->right = leaf;
        return;
      }
      tree = tree->right;
    }
  }
}

void preorder(FILE *dfd, TREENODE *tree) {
  if(tree != NULL){
    fprintf(dfd,"%s\n", tree->word);
    preorder(dfd, tree->left);
    preorder(dfd, tree->right);
  }
}

void inorder(FILE *dfd, TREENODE *tree) {
  if(tree!=NULL) {
    inorder(dfd, tree->left);
    fprintf(dfd, "%s\n", tree->word);
    inorder(dfd, tree->right);
  }
}

void freetree(TREENODE *tree) {
  if(tree != NULL){
    freetree(tree->left);
    freetree(tree->right);
    free(tree);
  }
}

int find(char key[K], TREENODE *tree) {
  if(tree==NULL)  return 0;
  for(;;) {
    if(strcmp(tree->word,key)==0) return 1;
    if(strcmp(tree->word,key)>0) {
      if(tree->left==NULL)  return 0;
      else tree=tree->left;
    }
    else {
      if(tree->right==NULL) return 0;
      else tree=tree->right;
      }
  }
}
