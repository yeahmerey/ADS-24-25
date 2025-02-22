#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ; 
    node * next ; 
    node(int x){
        val = x ; 
        next = NULL ; 
    }
}; 

struct sll{
    private : 
        node * head ; 
        node * tail ; 
        int len ; 
    public : 
        ll(){
            head = tail = NULL ; 
            len = 0 ;
        }
        add(int x){
            node * n = new node(x); 
            len ++ ; 
            if(head == NULL){
                head = tail = n ; 
            }
            else{
                tail->next = n ; 
                tail = n ; 
            }
        }
        print(){
            node * cur = head ; 
            while(cur != NULL){
                cout << cur->val << " " ; 
                cur = cur->next; 
            }
        }    
}