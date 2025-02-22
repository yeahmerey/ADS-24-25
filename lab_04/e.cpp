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

node * find(node * root , int x){
    if(root == NULL ) return NULL ; 
    if(root->val == x) return root ; 
    node * tap = find(root->left , x) ; 
    if(tap == NULL)
        tap = find(root->right , x) ; 
    return tap ;      
};

int getH(node * cur){
    if(cur == NULL){
        return 0 ; 
    }
    int lheight = getH(cur->left) ; 
    int rheight = getH(cur->right);
    return (lheight > rheight) ? (lheight + 1) : (rheight + 1); 
}

int get_width (node* cur , int lvl){
    if(cur == NULL){
        return 0 ; 
    }
    if(lvl == 1){
        return 1 ; 
    }
    else{
        return get_width(cur->left , lvl - 1) + get_width(cur->right , lvl-1);
    }
}

int getMax(node * cur){
    int mx = 0 , width ; 
    int h = getH(cur); 
    for(int i = 1 ; i <=h ; i ++){
        width = get_width(cur , i); 
        if(width > mx){
            mx = width ; 
        }
    }
    return mx ;
}

int main(){
    node * root = new node(1) ; 
    node * cur ; 
    int n ; cin >> n ; 
    for(int i = 1 ; i < n ; i ++){
        int x , y , z ; cin >> x >> y >> z ; 
        cur = find(root , x); 
        node * main = new node(y) ;
        if(z == 0)
            cur->left = main ; 
        else cur->right = main ;     
    }
    cout << getMax(root) ;
}