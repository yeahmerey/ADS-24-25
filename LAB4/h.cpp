#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

struct bst {
private:
    node *root;
    node *add(node *cur, int x) {
        if (cur == NULL) {
            return new node(x); 
        }
        if (x < cur->val) {
            cur->left = add(cur->left, x);
        } else {
            cur->right = add(cur->right, x);
        }
        return cur;
    }

    void reverseInOrder(node *cur, int &sum) {
        if (cur == NULL) return;
        reverseInOrder(cur->right, sum);
        sum += cur->val;
        cur->val = sum;
        reverseInOrder(cur->left, sum);
    }

    void inOrderPrint(node *cur) {
        if (cur == NULL) return;
        inOrderPrint(cur->right);
        cout << cur->val << " ";
        inOrderPrint(cur->left);
    }

public:
    bst() {
        root = NULL;
    }

    void add(int x) {
        root = add(root, x);
    }

    void solve() {
        int sum = 0;
        reverseInOrder(root, sum); 
        inOrderPrint(root); 
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    bst *tree = new bst();
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        tree->add(k);
    }
    tree->solve();
    return 0;
}