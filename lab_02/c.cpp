#include <bits/stdc++.h>
using namespace std ;

struct node{
    int val ; 
    node * next ; 
    node * prev ; 
    node (int x){
        val = x ;
        next = prev = NULL ; 
    }
};  

struct ll{
    private:
        node * head ; 
        node * tail ; 
        int len ;
    public:     
        ll(){
            head = tail = NULL ; 
            len = 0 ; 
        }
        void push_back(int x){
            node * n = new node(x); 
            len++ ; 
            if(tail == NULL){
                head = tail = n ; 
            }
            else{
                tail->next = n ; 
                n->prev = tail ; 
                tail = n ; 
            }
        }
        void remove(){
            if (head == NULL){
                return ; 
            }
            node * cur = head ; 
            int ind = 1 ; 
            while(cur!=NULL){
                if(ind%2 == 0){
                    node * temp = cur ; 
                    if(temp->prev !=NULL){temp->prev->next = temp->next ; }
                    if(temp->next !=NULL){temp->next->prev = temp->prev ; }
                    if(temp == head ){head = temp->next ;}
                    if(temp == tail) {tail = temp->prev ;}
                    cur = cur->next ;  
                    delete temp ; 
                    }
                else{
                    cur= cur->next ;
                }
                ind++; 
            }
        }
        void print(){
            node * cur = head; 
            while(cur!=NULL){
                cout << cur->val << " " ; 
                cur = cur->next ; 
            }
            cout << endl ; 
        }
};
int main(){
    ll l1 ; 
    int n , t ; cin >> n ; 
    for(int i = 0 ; i <n ; i ++){
        cin >> t ; 
        l1.push_back(t) ; 
    }
    l1.remove() ; 
    l1.print() ; 
}