#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val ; 
    node * left;  
    node * right ; 
    node(int x){
        val = x ; 
        left = right = NULL ; 
    }
}; 

struct bst{
    public : 
        bst(){
            root = NULL ; 
        }
        void print(){
            print(root) ; 
        }
        bool search(int x){
            return search(root , x) != NULL ; 
        }
    private : 
        node * root ; 
        node * add(node * cur , int x){
            if(cur == NULL){
                cur = new node(x) ; 
            }
            else if(cur->val > x){
                cur->left = add(cur->left , x); 
            }
            else if(cur->val < x){
                cur->right = add(cur->right , x); 
            }
            return cur ; 
        }

        void print(node * cur){
            if(cur != NULL){
                print(cur->left) ; 
                cout << cur->val << " " ; 
                print(cur->right) ; 
            }
        }
        node * search(node * cur , int x){
            if(cur == NULL) return NULL ; 
            if(cur->val == x) return cur ; 
            if(cur->val > x) return search(cur->left , x) ; 
            return search(cur->right , x) ; 
        }
        node * del(node * cur , int x){
            if(cur == NULL) return ; 
            if(x < cur->val){
                cur->left = del(cur->left , x) ; 
            }
            else if(x > cur->val){
                cur->right = del(cur->right , x) ;
            }
            else{
                if(cur->left == NULL && cur->right == NULL){
                    //case 1 no child 
                    delete cur ; 
                    return NULL ; 
                }
                else if(cur->left == NULL){
                    //case 2 : one child(right)
                    node * temp  = cur->right; 
                    delete cur ; 
                    return temp ; 
                }
                else if(cur->right == NULL){
                    //case 2 : one child(left)
                    node * temp = cur->left ; 
                    delete cur ; 
                    return temp; 
                }
                else{
                    node * succ = findMin(cur->right); 
                    cur->val = succ->val ; 
                    cur->right = del(cur->right , succ->val); 
                }
            }
            return cur; 
        }
        node * findMin(node * cur){
            while(cur->left != NULL){
                cur = cur->left ; 
            }
            return cur ; 
        }
};   