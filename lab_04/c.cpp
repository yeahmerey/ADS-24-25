#include <bits/stdc++.h>
using namespace std;

struct node{
    node * right ; 
    node * left ; 
    int val ; 
    node (int x){
        val = x ; 
        right = left = NULL ;  
    }
}; 
struct bst{
    private : 
        node * root ;
        node * add(node * cur , int x){
            if(cur == NULL){
                cur = new node(x);
            }
            else if(cur->val < x){
                cur->right = add(cur->right , x) ; 
            }
            else if(cur->val > x){
                cur->left = add(cur->left , x) ; 
            }
            return cur ; 
        }
        node * find(node * cur , int x){
            if(cur == NULL) return NULL ; 
            if(cur->val == x) return cur ; 
            if(cur->val > x) return find(cur->left , x) ; 
            else return find(cur->right , x) ; 
        }
        void print(node * cur){
            if(cur!=NULL){
                print(cur->left) ; 
                cout << cur->val << " " ; 
                print(cur->right) ; 
            }
        }
        void solve(node * root2){
            if(root2 != NULL){
                cout << root2->val << " ";
                solve(root2->left) ; 
                solve(root2->right) ;
            }
        }
    public :
        bst(){
            root = NULL ; 
        }    
        void add(int x){
            root = add(root , x) ; 
        }
        bool find(int x){
            return find(root , x) != NULL ;  
        }
        void print(){
            print(root) ;  
        }
        void solve(int x){
            node * root2 = find(root , x) ; 
            solve(root2) ; 
        }
};

int main(){
    int n , m ; cin >> n ; 
    bst * tree = new bst ; 
    for(int i = 0 ; i < n ; i ++){
        int san ; cin >> san ; 
        tree->add(san) ; 
    }
    int k ; cin >> k ; 
    tree->solve(k); 
}