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
        int len ; 
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
        int solve(node * root2){
            if(root2 != NULL){
                len++; 
                solve(root2->left) ;
                solve(root2->right) ;
            }
            return len ; 
        }

        
    public :
        bst(){
            root = NULL ;
            len = 0 ; 
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
        int solve(int x){
            node * root2 = find(root , x);
            return solve(root2);  
        }
};

int main(){
    int n ; cin >> n; 
    bst * tree = new bst ; 
    for(int i = 0 ; i < n ; i ++){
        int san ; cin >> san ; 
        tree->add(san) ; 
    }
    int m ; cin >> m ; 
    cout << tree->solve(m) ; 
}