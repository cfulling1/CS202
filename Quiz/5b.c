Write a function named nodecount that has the root of a binary tree as parameter, and which returns the
maximum value in the tree.

typedef struct tree {
    int data;
        struct tree *left, *right;
        } TREE;



int nodecount(TREE *tree) {
  int max;
  int leftmax, rightmax;
  
  max=tree->data;
  leftmax=nodecount(tree->left);
  rightmax=nodecount(tree->right);
  
  if(leftmax>rightmax)  max=leftmax;
  if(rightmax>leftmax)  max=rightmax;
  
  return max;
}




5. Write a C function named reverse that has an unsigned char as parameter. The function should count the number one-bit pairs.


unsigned char reverse(unsigned char x) {
  int mask=3;
  int count=0;
  
  while(x!=0) {
    if((x & mask)==3)  {
      count++;
      x=x>>1;
    }
    
    
  }
}
