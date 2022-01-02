
#include <cstdio>
#include <stack>
#include <cmath>

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

//get level of node
int getlvl(node *root){
    if(root == NULL)
        return 0;
    else{
        int l = getlvl(root -> left);
        int r = getlvl(root -> right);
        return max(l, r) + 1;
    }
}

bool HeightOfTree(node* v){
    int x, y;
    if (v == NULL) return true;     //РїСѓСЃС‚РѕРµ РґРµСЂРµРІРѕ РёР»Рё РґРѕС€Р»Рё РґРѕ Р»РёСЃС‚Р°
    x = getlvl(v -> left);
    y = getlvl(v -> right);
    if(abs(x-y) <= 1 && HeightOfTree(v->left) && HeightOfTree(v->right))
        return true;
    return false;
}


int main(void)

{

    while(scanf("%d",&n), n)

        insert(tree,n);
    if(HeightOfTree(tree)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    printf("\n");
    return 0;
}

 