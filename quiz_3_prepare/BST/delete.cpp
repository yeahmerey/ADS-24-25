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
            delete cur ; 
            return NULL ; 
        }
        else if(cur->left == NULL){
            node * temp  = cur->right; 
            delete cur ; 
            return temp ; 
        }
        else if(cur->right == NULL){
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