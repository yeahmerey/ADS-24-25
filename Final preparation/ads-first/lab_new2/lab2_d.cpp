#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ; 
    node * next ; 
    node * prev ; 
    node (int x){
        val = x ;
        next = prev = NULL ; 
    }
};  

struct ll {
    private : 
        node * head ; 
        node * tail ; 
        int len ; 
    public:
        ll(){
            head = tail = NULL ; 
            len = 0 ; 
        }
        void push_back(int m ){
            node * n = new node(m) ; 
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
        void print(){
            node * cur = head ; 
            while(cur!=NULL){
                cout << cur->val << " " ; 
                cur = cur->next ; 
            }
        }
        void insert(int data , int p){
            node * t = new node(data) ; 
            if(p == 0){
                t->next = head ; 
                if(head != NULL){
                    head->prev = t ; 
                }
                head = t ; 
                if(tail == NULL){
                    tail = t ; 
                }
            }
            else{
                node * cur = head ; 
                for(int i = 0;  i< p-1 ; i ++){
                    cur = cur->next ; 
                }
                if(cur == tail ){
                    tail->next = t ; 
                    t->prev= tail ; tail = t ; 
                }
                else if(cur!=NULL){
                    node * curne = cur->next ; 
                    cur->next = t ; 
                    t->prev =cur ; 
                    t->next = curne ; 
                    if(curne != NULL){
                        curne->prev =  t ; 
                    }
                }
            }
        }
}; 
int main(){

    ll l1 ; 
    int n ; cin >> n ; int d ;  
    for(int i = 0 ; i < n ; i ++){
        cin >> d ; 
        l1.push_back(d) ; 
    }
    int data , pos; cin >> data >> pos ;

    l1.insert(data , pos) ; 
    l1.print() ; 
}