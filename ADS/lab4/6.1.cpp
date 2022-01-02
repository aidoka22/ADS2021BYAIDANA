#include <cstdio>
#include <stack>

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

 
void inorder(node *v) {
    if (v == NULL) return;
    inorder(v->left);
    inorder(v->right);
}
void prove(node* v){
    if (v->left){
        prove(v->left);
    }
    if(v->left!=NULL and v->right!=NULL ){
        printf("%d\n",v->key);
    }
    if(v->right){
        prove(v->right);
    }
}
int main(void){
  while(scanf("%d",&n), n)
    insert(tree,n);
  inorder(tree);  
  prove(tree);
  printf("\n");
  return 0;
}

 