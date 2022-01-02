#include <bits/stdc++.h> 
using namespace std; 
int counter = 0; 
struct node {
    int key;
    node *left;
    node *right;
    node(int key) { 
        left = right = NULL;
        this->key = key;
    }
} *root;

node* find(node *v, int key) {
    if (v == NULL) return NULL;
    if (v->key == key) return v;
    if (key <= v->key)
        return find(v->left, key);
    return find(v->right, key);
}

node* insert(node *&v, int key) {
    if (v == NULL) {
        v = new node(key);
        return v;
    }
    if (find(v, key)) return v;
    if (key <= v->key)
        return insert(v->left, key);
    return insert(v->right, key);
}

int inorder(node *node){
    if(node ==NULL){
        return 0;
    }
    inorder(node->left);
    if((node->left != NULL) && (node->right != NULL)){
        counter++;
    }  
    inorder(node->right);
    return counter;
}

int main() 
{   
    int n;
    int x; 
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>x;
        insert(root, x);
    }
    
    cout<<inorder(root);
    return 0; 
} 