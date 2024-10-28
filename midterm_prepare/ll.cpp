#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ; 
    node * prev ; 
    node * next ; 
    node(int x){
        val = x ;
        prev = next = nullptr ; 
    }
}; 

struct ll{
    private : 
        node * head ; 
        node * tail ; 
        int len ; 
    public : 
        ll(){
            head = tail = nullptr ; 
            len = 0 ; 
        }    
        void push_front(int x){
            node * n = new node(x); 
            len++ ; 
            if(head == null){
                head =tail = n ; 
            }
            else{ 
                head->prev = n ; 
                n->next = head ; 
                head = n ; 
            }
        }
        void push_back(int x){
            node * n = new node(x); 
            len++; 
            if(head == null){
                head = tail = n ; 
            }
            else{
                tail-> next = n ; 
                n->prev = tail 
                tail = n ; 
            }
        }
        void print(){
            node * cur = head; 
            while(cur!=nullptr){
                cout << cur->val << " "; 
                cur = cur->next ;
            }
        }
        void pop_front(){
            if(head == nullptr) return -1 ;
            node * n = head; 
            if(head->next !=nullptr){
                head = head->next ; 
                head->prev = nullptr ;
            }
            else{
                head = tail = nullptr
            }
            delete n ;
        }
        void pop_back(){
            if(tail==nullptr){
                return -1 ;
            }
            node * n = tail ; 
            if(tail->prev!=nullptr){
                tail = tail->prev; 
                tail->next = nullptr; 
            }   
            else{
                head = tail = nullptr ; 
            }
            delete n ; 
        }
}