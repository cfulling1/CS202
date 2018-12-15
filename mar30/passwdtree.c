#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define K 1024

typedef struct treenode {
char *login;
int uid;
char *realname;
struct treenode *left, *right;
} TREENODE;

TREENODE *makenode(char login[K], int uid, char realname[K]);
void decorate(TREENODE *tree, TREENODE *leaf);
void freetree(TREENODE *tree);
int maxdepth(TREENODE *tree);
void logincase(char logincase[K], TREENODE *tree);
void uidcase(int uid, TREENODE *tree);
void realnamecase(char name[K], TREENODE *tree);

int main() {
  TREENODE *root;
  TREENODE *ptr;
  root=0;

  char login[K];
  int uid;
  char realname[K];

  int count;
  int numcount=0;
  char buffer[K];
  char *line;

  int i;

  char cmd[K];

  FILE *fp = fopen("/etc/passwd", "r");
  if(fp<0) {
    fprintf(stderr, "could not open the password file\n");
    exit(0);
  }

  while(fgets(buffer,K,fp)!=NULL) {
    for(i=0; i<strlen(buffer); i++) {
      if(buffer[i]==',')  buffer[i]='\0';
    }
    count=0;
    line=strtok(buffer, ":");
    while(line!=NULL) {
      count++;
      if(count==1) strcpy(login,line);
      if(count==3) uid=atoi(line);
      if(count==5) {
	      strcpy(realname,line);
	      if(root == NULL) {
	        numcount++;
	        root = makenode(login,uid,realname);
	      }
	      else {
	        numcount++;
	        ptr = makenode(login,uid,realname);
	        decorate(root,ptr);
	      }
      }
     line=strtok(NULL,":");
    }
  }

  printf("%d items\n", numcount);

  int depth=maxdepth(root);
  printf("max depth is %d\n\n",depth);

  for(;;) {
    printf("? ");
    fgets(cmd,K,stdin);
    switch(cmd[0]) {
      case 'l':
      	line=strtok(cmd,"=");
  	    line=strtok(NULL,"\n");
	      strcpy(login,line);
	      logincase(login,root);
	      break;
      case 'n':
	      line=strtok(cmd,"=");
	      line=strtok(NULL,"\n");
	      strcpy(realname,line);
	      realnamecase(realname,root);
        break;
      case 'u':
	      line=strtok(cmd,"=");
	      line=strtok(NULL,"\n");
	      uid=atoi(line);
	      uidcase(uid,root);
	      break;
      case 'q': return 0;
      default: fprintf(stderr, "invalid command %s\n", cmd);
    }
  }
  freetree(root);
}


TREENODE *makenode(char a[K], int b, char c[K]) {
  TREENODE *p;
  p = malloc(sizeof(TREENODE));

  p->login=malloc(sizeof(char)*K);
  strcpy(p->login, a);

  p->realname=malloc(sizeof(char)*K);
  strcpy(p->realname, c);

  p->uid=b;

  p->left = 0;
  p->right = 0;

  return p;
}

void decorate(TREENODE *tree, TREENODE *leaf) {
  for(;;) {
    if(strcmp(leaf->realname,tree->realname)<0) {
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

void freetree(TREENODE *tree) {
  if(tree!=NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free(tree);
  }
}

int maxdepth(TREENODE *tree) {
  int leftdepth, rightdepth;
  if(tree == NULL)  return 0;
  leftdepth  = maxdepth(tree->left);
  rightdepth = maxdepth(tree->right);
  return (leftdepth > rightdepth) ? leftdepth + 1 : rightdepth + 1;
}

void uidcase(int uidno, TREENODE *tree) {
  if(tree!=NULL) {
    uidcase(uidno,tree->left);
    if(uidno == tree->uid) {
      printf("%s:", tree->login);
      printf("%d:", tree->uid);
      printf("%s\n", tree->realname);
    }
    uidcase(uidno,tree->right);
  }
}

void logincase(char login[K], TREENODE *tree) {
  char *ptr;
  if(tree!=NULL) {
    logincase(login,tree->left);
    ptr=strcasestr(tree->login,login);
    if(ptr) {
      printf("%s:", tree->login);
      printf("%d:", tree->uid);
      printf("%s\n", tree->realname);
    }
    logincase(login,tree->right);
  }
}

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

