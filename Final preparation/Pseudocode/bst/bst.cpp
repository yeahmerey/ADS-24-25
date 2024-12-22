#include <bits/stdc++.h>
using namespace std;

struct node{
    node * left ; 
    node * right ; 
    int val ; 
    node(int x){
        val = x; 
        left = right = NULL ;
    }
}; 

struct bst{
    public: 
        bst(){
            root = NULL ; 
        }
        void add(int x){
            root = add(root , x) ; 
        }
        void print(){
            print(root); 
        }
        bool search(int x){
            return search(root , x) !=NULL; 
        }
    private :
        node * root ; 
        //operation insert
        node * add(node * cur, int x){
            if(cur == NULL){
                cur = new node(x) ;
            }
            else if(cur->val < x){
                cur->right = add(cur->right , x); 
            }
            else if(cur->val > x){
                cur->left = add(cur->left , x);
            }
            return cur ;
        }
        //operation find
        void * search(node * cur , int x){
            if(cur == NULL) return false ;
            if(cur->val == x) return cur ; 
            if(cur->val > x) return search(cur->left , x); 
            else return search(cur->right , x) ;
        }
        //operation delete : 
        node * getSuccessor(node * cur){
            cur = cur->right ; 
            while(cur!= nullptr && cur->left!= nullptr)
                cur = cur->left; 
            return curr ;    
        }
        node * delete(node * cur , int x){
            if(root == nullptr)
                return root ; 
            if(root->key > x){
                root->left = delete(root->left , x); 
            }
            else if(root->key < x){
                root->right = delete(root->right , x) ; 
            }
            else{
                if(root->left == nullptr){
                    node * temp = root->right ; 
                    delete root ; 
                    return temp; 
                }
                if(root->right == nullptr){
                    node * temp = root->left ; 
                    delete root ; 
                    return temp; 
                }
                node * succ = getSuccessor(root) ; 
                root->key = succ->key ; 
                root->right = delete(root->right , succ->key); 
            }
            return root; 
        }
        // in order travel ; 
        void printInOrder(node * cur){
            if(cur!= NULL){
                printInOrder(cur->left) ; 
                cout << cur->val << " " ; 
                printInOrder(cur->right); 
            }
        }
        //pre order travel : 
        void printPreOrder(node * cur){
            if(cur!=NULL){
                cout << cur->val << " " ;
                printPreOrder(cur->left); 
                printPreOrder(cur->right);  
            }
        }
        //post order travel  : 
        void printPostOrder(node * cur){
            printPostOrder(cur->left); 
            printPostOrder(cur->right); 
            cout << cur->val << " "; 
        }

}