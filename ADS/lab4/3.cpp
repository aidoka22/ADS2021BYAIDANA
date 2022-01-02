#include <iostream>
#include <cassert>
using namespace std;
struct node

{

  int key;

  node *left, *right;
  node(int z) : key(z), left(NULL), right(NULL) {}

}*root; 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<  root->key; 
        inorder(root->right); 
    } 
} 
void insert(node *&v, int n)

{

  if (!v)

  {

    v = new node(n);

    return;

  }

  if (v->key == n) return;

  if (n < v->key) insert(v->left,n);

  else insert(v->right,n);

}

node* MaxValue(node* v)
{
    if (v->right != NULL) {
        return  MaxValue(v->right);
    }
    else {
        return v;
    }
}
node* find(node *v, int x) {
    if (v == NULL) return NULL;
    if (v->key == x) return v;
    if (x <= v->key)
        return find(v->left, x);
    return find(v->right, x);
}
struct node * MinValue(struct node* v) 
{ 
    struct node* current = v; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
struct node* deleteNode(struct node* root,struct node* key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key <  root-> key ) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = MinValue(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

int main(void)
{
  node *v=NULL;
  int n;
  int key;
  while(scanf("%d",&n), n)
    insert(v,n);
  node* max = MaxValue(v);
  inorder(v);
  v=deleteNode(v,max);
  node* max2 = MaxValue(v);
  printf("%d",max2);
  printf("\n");
  return 0;
  return 0;
}