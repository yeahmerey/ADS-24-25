#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ;
    node * left ;
    node * right ;
    node(int x){
        val = x ;
        left = right = NULL ;
    }
};

struct bst{
private :
    node * root ;
    node * add(node * cur , int x){
        if(cur == NULL){
            cur = new node(x);
        }
        if(cur->val < x) {
            cur->right = add(cur->right , x);
        }
        else if(cur->val > x){
            cur->left = add(cur->left , x);
        }
        return cur ;
    }
    int checker(node * cur){
        if(cur == NULL) { return  0 ; }
        int cnt = 0 ;
        if(cur ->left != NULL && cur->right !=NULL){
            cnt++; 
        }
        cnt+= checker(cur->left);
        cnt+=checker(cur->right);
        return cnt ;
    }
public :
    bst(){
        root = NULL ;
    }
    void add(int x){
        root = add(root , x) ;
    }
    void solve(){
        cout << checker(root);
    }
};
int main(){
    int n ; cin >> n ;
    bst * tree = new bst();
    for(int i = 0 ; i < n ; i ++){
        int k ; cin >> k ;
        tree->add(k);
    }
    tree->solve();
    return 0 ; 
}