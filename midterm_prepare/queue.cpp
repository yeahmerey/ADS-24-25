#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ; 
    node * next; 
    node(int x){
        val = x; 
        next = NULL ;
    }
};

struct queue{
    private : 
        node * head ; 
        node * tail ; 
        int len ; 
    public : 
        queue(){
            head = tail = NULL ; 
            len = 0 ; 
        }
        void push(){
            node * n = new node(x); 
            if(tail == NULL){
                head = tail = NULL ; 
            }
            else{
                tail->next = n;  
                tail = n ;
            }
        }
        void pop(){
            if(head == null) return -1; 
            else{
                int value = head->value ; 
                node * temp = head; 
                head = head->next; 
                delete temp;  
            }
        }    
}

void push(int x){
    node * n = new node(x); 
    if(head == nullptr){head=tail=n; }
    else{
        tail->next = n ; 
        tail = n; 
    }
}
void pop(){
    if(head == NULL) return -1 ;
    else{
        int val = head->value ;
        node * temp = head; 
        head = head->next ;
        delete temp ; 
    }
}