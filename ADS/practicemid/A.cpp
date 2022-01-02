
#include <cstdio>
#include <vector>
#include<iostream>
using namespace std;



struct node

{

  int key;

  node *left, *right;

  node(int x) : key(x), left(NULL), right(NULL) {}

};

 

node *tree;

int i, n, flag = 0;

 

void insert(node *&tree, int n)

{

  if (!tree)

  {

    tree = new node(n);

    return;

  }

  if (tree->key == n) return;

  if (n < tree->key) insert(tree->left,n);

  else insert(tree->right,n);

}
vector<int> q;
void prove(node* v){
    if (v == NULL)
        return;
        
    prove(v->right);
    q.push_back(v ->key);
    prove(v->left);
}
int main()
{
  while(cin>>n && n!=0)
    insert(tree,n);
  prove(tree);
  int sum=0;
  for(int i=0;i<q.size();i++){
    sum=sum+q[i];
    cout<<sum<<" ";
  }
  return 0;
}