#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;


class TreeNode {
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
    
    TreeNode (int val) {
        this -> val = val;
        left = NULL;
        right = NULL;
    }
};

int dp[500500];

class BST {
    public:
        TreeNode * root;
    
    BST () {
        root = NULL;
    }

    TreeNode * insert (TreeNode * root, int val) {
        if (root == NULL) {
            root = new TreeNode (val);
            dp[val] = 1;
            return root;
        }

        if (val < root -> val) {
            root -> left = insert (root -> left, val);
            if (root -> left != NULL)
                dp[root -> val] = max(dp[root -> val], dp[root -> left -> val] + 1);
        } else {
            root -> right = insert (root -> right, val);
            if (root -> right != NULL)
                dp[root -> val] = max(dp[root -> val], dp[root -> right -> val] + 1);
        }
        return root;
    }
};


int main() {
    
    BST * bst = new BST ();

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bst -> root = bst -> insert (bst -> root, x);
    } 

    int m; cin >> m;

    cout << dp[m] << endl;

    return 0;
}