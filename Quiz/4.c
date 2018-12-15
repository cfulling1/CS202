int nodecount(TREE *tree) {
  if(tree==NULL)  return 0;
  return 1+nodecount(tree->left)+nodecount(tree->right);
}
