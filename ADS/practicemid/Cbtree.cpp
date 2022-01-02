#include <cstdio>

#include <stack>

using namespace std;

 

struct TreeNode

{

  int data;

  TreeNode *left, *right;

  TreeNode(int x) : data(x), left(NULL), right(NULL) {}

};

 

TreeNode *tree;

int i, n, flag = 0;

 

void insert(TreeNode *&tree, int n)

{

  if (!tree)

  {

    tree = new TreeNode(n);

    return;

  }

  if (tree->data == n) return;

  if (n < tree->data) insert(tree->left,n);

  else insert(tree->right,n);

}

 

void InOrderNR(TreeNode *tree)

{
  int count=0;
  if (tree == NULL) return;

  stack<TreeNode *> s;

  TreeNode *current = tree;

  while(!s.empty() || current)

  {

    if (current)

    {

      s.push(current);

      current = current->left;

    } else

    {

      current = s.top();

      s.pop();

      if((current->left == NULL) && (current->right == NULL))

      {

        if (flag) printf(" ");      

        count++;

        flag = 1;

      }

      current = current->right;

    }

  }
  printf("%d",count);

}

 

int main(void)

{

  while(scanf("%d",&n), n)

    insert(tree,n);

 

  InOrderNR(tree);

  printf("\n");

 

  return 0;

}

 