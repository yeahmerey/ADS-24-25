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
            int level = 0;
            root = add(root, x, level);
        }
        void solve(){
            cout << all_sum.size() << endl;
            for(int i = 0; i < all_sum.size(); i++){
                cout << all_sum[i] << " ";
            }

        }

    private:
        node* root;
        vector<int> all_sum;
        node* add(node * cur, int x, int level){
            if (cur == NULL){
                if(level >= all_sum.size()) all_sum.push_back(x);
                else all_sum[level] += x;
                cur  =  new node(x);
            }else if(x < cur->val){
                cur -> left = add(cur->left, x, ++level);
            }else if(cur->val < x){
                cur->right = add(cur->right, x, ++level);
            }
            return cur;
        }

};

int main(){
    int n; cin >> n;
    bst* tree = new bst();
    for(int i = 0; i < n;i++){
        int t ; cin >> t ; 
        tree -> add(t);
    }
    tree -> solve();
  
    // tree->print();
    // cout << endl << tree->find(10);
    // cout <<endl << tree->find(20);

}