#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define K 1024

typedef struct treenode {
  int data;
  struct treenode *left, *right;
} TREENODE;

TREENODE *makenode(int n);
void decorate(TREENODE *tree, TREENODE *leaf);
void freetree(TREENODE *tree);
int maxdepth(TREENODE *tree);

int main(int argc, char *argv[]) {
  TREENODE *root;
  TREENODE *ptr;

  int x;
  root = 0;
	for(int i=0; i<1000; i++) {
  	scanf("%d", &x);
    if(root == NULL){
     	root = makenode(x);
    }
    else {
     	ptr = makenode(x);
     	decorate(root,ptr);
    }
  }
	printf("max depth: %d\n", maxdepth(root));
  freetree(root);
}

TREENODE *makenode(int n) {
  TREENODE *p;

  p = malloc(sizeof(TREENODE));
  p->data=n;
	p->left = p->right = 0;
  return p;
}

void decorate(TREENODE *tree, TREENODE *leaf) {
  for(;;){
    if(leaf->data < tree->data){
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

void freetree(TREENODE *tree) {
  if(tree != NULL){
    freetree(tree->left);
    freetree(tree->right);
    free(tree);
  }
}

int maxdepth(TREENODE *tree) {
  int leftdepth, rightdepth;

  if(tree == NULL)
    return 0;
  leftdepth  = maxdepth(tree->left);
  rightdepth = maxdepth(tree->right);
  return (leftdepth > rightdepth) ? leftdepth + 1 : rightdepth + 1;
}
