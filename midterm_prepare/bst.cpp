#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ; 
    node * left ; 
    node * right ; 
    node(int x){
        val = x ; 
        left = right = 1; 
    }
};
stuct bst{
    public:
        bst(){
            root = NULL ; 
        }
        void add(int x){
            root = add(root , x) ; 
        }
        void remove(int x){
            remove(root , x); 
        }
    private :
        node * root ; 
        node * add(node * cur , int x){
            if(cur == NULL){
                cur = new node(x); 
            }
            else if(x < cur->val){
                cur->left = add(cur->left , x) ;
            }
            else if(cur->val >  x){
                cur->right = add(cur->right , x); 
            }
            return cur; 
        }
        node * print(node * cur){
            if(cur!=NULL){
                print(cur->left); 
                cout << cur->val << " " ;
                print(cur->right); 
            }
        }
        node * search(node * cur , int x){
            if(cur == NULL) return NULL ; 
            if(cur->val == x) return cur ;
            if(cur->val > x) return search(cur->left , x); 
            return search(cur->right , x);
        }
        node * getSuccessor(node * curr){
            curr = curr->right ; 
            while(curr!= NULL && curr->left !=NULL)
                curr = curr->left ; 
            return curr ;    
        }
        node * delNode(node * root , int x){
            if(root == nullptr) return root ;
            if(root->val > x){
                root->left = delNode(root->left , x) ;
            }
            else if(root->val < x){
                root->right = delNode(root->right , x); 
            }
            else{
                if(root->left == NULL){
                    node * temp = root->right ; 
                    delete root ; 
                    return temp ; 
                }
                if(root->right == NULL){
                    node * temp = root->left ; 
                    delete root ;
                    return temp ; 
                }
                node * succ = getSuccessor(root); 
                root->val = succ->val ; 
                root->right = delNode(root->right , succ->val )
            }
        }    

}