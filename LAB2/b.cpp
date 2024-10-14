#include <bits/stdc++.h>
using namespace std;

struct node{
    string val ;
    node * next ;
    node * prev ;
    node(string x){
        val = x ;
        next = prev = NULL ;
    }
};

struct ll {
    private :
        node * head ;
        node * tail ;
        int len ;
    public :
        ll(){
            head = tail = NULL ;
            len = 0 ;
        }
        void push_front(string x){
            node * n = new node(x) ;
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
        void push_back(string x){
            node * n = new node(x) ;
            len++ ;
            if(head == NULL){
                head = tail = n ;
            }
            else{
                tail->next = n ;
                n->prev =tail ;
                tail = n  ;
            }
        }
        void print(){
            node *cur = head ;
            while(cur!= NULL){
                cout << cur->val << " " ;
                cur = cur->next ;
            }
        }
        void newlist(int m ){
        if(head == NULL) return ;
        m = m % len;
        if(m == 0) return ;
        node * cur = head ;
        for(int i = 0 ; i < m ; i ++){
            cur = cur->next ;
        }
        node * newtail = cur->prev ;
        newtail->next = NULL ;
        head->prev = NULL ;
        tail -> next = head ;
        head = cur ;
        tail = newtail  ;


        // node * newhead = cur->next ;
        // cur->next = NULL ;
        // tail ->next = head;
        // head = newhead ;
        // tail = cur ;
    }
};
int main(){
    ll l1  ;
    int n , m ; cin >> n >> m ; string t ;
    for(int i = 0 ; i < n ; i ++){
        cin >> t ;
        l1.push_back(t) ;
    }
    l1.newlist(m) ;
    l1.print() ;
}