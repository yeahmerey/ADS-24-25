#include <bits/stdc++.h>

using namespace std;
vector<int> v;
struct node
{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};


struct bst
{
    public:
        bst(){
            root = NULL;
        }
        void add (int x){
            root = add(root, x);
        }
        void inorder() {
            _inorder(root);
        }

        void preorder() {
            _preorder(root);
        }
        void solve(int l, int r){
            root = _solve(l, r);
        }

    private:
        node* root;
        
        node* add(node * cur, int x){
            if (cur == NULL){
                cur  =  new node(x);
            }else if(x < cur->val){
                cur -> left = add(cur->left, x);
            }else if(cur->val < x){
                cur->right = add(cur->right, x);
            }
            return cur;
        }
        void _inorder(node *cur) {
            if(!cur) {
                return;
            }
            _inorder(cur->left);
            v.push_back(cur->val);
            _inorder(cur->right);
        }
        void _preorder(node *cur) {
            if(!cur) {
                return;
            }
            cout << cur->val << " ";
            _preorder(cur->left);
            _preorder(cur->right);
        }

        node* _solve(int l, int r) {
            if(r < l) {
                return NULL;
            }
            int mid = l + (r - l) / 2;
            node* cur = new node(v[mid]);
            cur->left = _solve(l, mid - 1);
            cur->right = _solve(mid + 1, r);
            return cur;
        }


};

int main(){
    int n; cin >> n;
    int size = pow(2, n) - 1;

    bst *tree = new bst();
    for(int i = 0; i < size; i++) {
        int x; cin >> x;
        tree->add(x);
    }
    tree->inorder();
    tree->solve(0, size - 1);
    tree->preorder();

}