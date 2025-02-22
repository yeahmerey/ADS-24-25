#include <bits/stdc++.h>

using namespace std;

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
        void solve(){
            cout << maxDist();
        }

    private:
        node* root;
        vector<int> levels;
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
        int depth(node* node){
            if(!node) return 0;
            
            int left = depth(node->left);
            int right = depth(node->right);
            return max(left, right)+1;
        }
        int maxDist() {
            queue <node*> q;
            int res = -1;
            q.push(this->root);
            while(!q.empty()) {
                node *cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                int dis = depth(q.front()->left) + depth(q.front()->right) + 1;
                res = max(res, dis);
                q.pop();
            }
            return res;
        }
};

int main(){
    int n; cin >> n;
    int arr[n];
    bst* tree = new bst();
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        tree -> add(arr[i]);
    }
    tree -> solve();
}