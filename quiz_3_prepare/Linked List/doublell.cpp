#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ; 
    node * next ; 
    node * prev ; 
    node(int x){
        val = x; 
        prev = next = NULL ; 
    }
}; 
struct dll{
    private : 
        node * head ; 
        node * tail ; 
        int len ; 
    public : 
        dll(){
            head = tail = NULL ; 
            len = 0 ; 
        }
        void push_back(int x){
            node * n = new node(x) ; 
            if(tail == NULL){
                head = tail = NULL ;
            }
            else{
                tail->next = n ; 
                n->prev = tail ; 
                tail = n ; 
            }
        }
        void push_front(int x){
            node * n = new node(x) ; 
            if(head == NULL){
                head = tail = n ; 
            }
            else{
                head -> prev = n ; 
                n->next = head; 
                head = n ; 
            }
        }
        void pop_front(){
            if(head == NULL){
                cout << "List is empty" ; 
            }
            node * temp = head->next ; 
            head = head ->next ; 
            if(head != NULL){
                head ->prev = NULL ; 
            }
            delete temp ; 
            len -- ; 
         }
         void pop_back(){
            if(tail == NULL){
                cout << "List is empty" ; 
                return ; 
            }
            node * temp = tail ; 
            tail = tail->prev ;
            if(tail != NULL){
                tail->next = NULL ; 
            }
            delete temp ; 
            len -- ;   
         }
        void print(){
            node * cur = head;  
            while(cur != NULL){
                cout << cur->val << " "; 
                cur = cur->next ; 
            }
        }

}