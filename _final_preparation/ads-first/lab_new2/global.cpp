#include <bits/stdc++.h>
using namespace std;


struct node {
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
            node * n = new node(x) ; 
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
        void push_front(int x){
            node * n = new node(x); 
            len++ ; 
            if(head == NULL){
                head = tail = n ; 
            }
            else{
                head->prev = n ; 
                n->next = head ; 
                head = n ; 
            }
        }
        void print(){
            node * cur = head; 
            while(cur != NULL ){
                cout << cur->val << " " ; 
                cur = cur->next ; 
            }
        }
};

int main(){
    ll linklist1 ; 
    int n ; cin >> n ; int b;   
    for(int i = 0 ; i < n ; i ++){
        cin >> b ;
        linklist1.push_back(b) ; 
    }
    linklist1.print(); 
}