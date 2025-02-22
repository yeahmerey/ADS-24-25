#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    int cnt;
    node(int x){
        val = x;
        cnt = 1;
        left = right = NULL;
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
        void remove(int x){
            remove(root, x);
        }
        void cnt(int x){
            cnt(root,x);
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
            }else if(cur->val == x){
                cur->cnt++;
            }
            return cur;
        }
        void cnt(node *cur, int x) {
            if(!cur) {
                cout << 0 << endl;
                return;
            }
            if(cur->val < x) {
                cnt(cur->right, x);
            } else if(cur->val > x) {
                cnt(cur->left, x);
            } else {
                cout << cur->cnt << endl;
            }
        }
        void remove(node *cur, int x) {
            if(!cur) {
                return;
            }
            if(cur->val < x) {
                remove(cur->right, x);
            } else if(cur->val > x) {
                remove(cur->left, x);
            } else {
                if(cur->cnt > 0) {
                    cur->cnt--;
                }
            }
        }
};

int main(){
    int n; cin >> n;
    bst *tree = new bst();
    while(n--) {
        string c;
        int x;
        cin >> c >> x;
        if(c == "insert") {
            tree->add(x);
        } else if(c == "delete") {
            tree->remove(x);
        } else if(c == "cnt") {
            tree->cnt(x);
        }
    }

}