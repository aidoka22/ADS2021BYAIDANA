#include <cstdio>
#include <iostream>

using namespace std;
int count1=0,count2=0;
 

struct BinaryTree

{

  int data;

  BinaryTree *left, *right;

  BinaryTree(int z) : data(z), left(NULL), right(NULL) {}

}*root; 

void insert(BinaryTree *&v, int n)

{

  if (!v)

  {

    v = new BinaryTree(n);

    return;

  }

  if (v->data == n) return;

  if (n < v->data) insert(v->left,n);

  else insert(v->right,n);

}

 
int NumberOfNodes(BinaryTree* v) {
    if (v == NULL) return 0;
    return NumberOfNodes(v->left) + 1+ NumberOfNodes(v->right);
}
int main(void)
{
  BinaryTree *v=NULL;
  int n;
  while(scanf("%d",&n), n)
    insert(v,n);
  printf("%d",NumberOfNodes(v));
  printf("\n");
  return 0;
}