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

 
int HeightOfTree(BinaryTree* v) {
    int x = 0, y = 0;
    if (v == NULL) return 0;     //пустое дерево или дошли до листа
    if(v->left) x = HeightOfTree(v->left); //высота левого поддерева
    if (v->right) y = HeightOfTree(v->right);  //высота правого поддерева
    if (x > y) return x + 1;    //+1 от корня к левому поддереву
    else return y + 1;   //+1 от корня к правому поддереву
} 
int main(void)
{
  BinaryTree *v=NULL;
  int n;
  while(scanf("%d",&n), n)
    insert(v,n);
  printf("%d",HeightOfTree(v));
  printf("\n");
  return 0;
}