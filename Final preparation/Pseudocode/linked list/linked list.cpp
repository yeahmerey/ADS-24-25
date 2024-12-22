#include <bits/stdc++.h>
using namespace std;

struct node{
    int val; 
    node * next; 
    node(int x){
        val = x; 
        next = nullptr ;
    }
}; 
struct linkedlist{
    private: 
        node * head ; 
        node * tail ; 
        int len ; 
    public : 
        linkedlist(){
            head = tail = NULL ; 
            len = 0 ;
        }
        add_to_front(int x){
            node * n = new node(x) ;
            len++; 
            if(head == NULL){
                head = tail = n ;
            }
            else{
                n->next = head; 
                head = n ; 
            }
        }    
        add_with_zadannym_uzel(node * head , int key , int newData){
            node * cur = head;  
            while(cur!=nullptr){
                if(cur->data == key){
                    break ; 
                }
                cur = cur->next;  
            }
            if(cur == nullptr){
                return NULL; //берілген ключ жоқ. 
            }
            node * newNode = new Node(newData); 
            cur->next = newNode ; 
        }
        add_back(int x){
            node * n = new node(x) ; 
            len ++; 
            if(head == NULL){
                head = tail = n ; 
            }
            else{
                tail->next = n ; 
                tail=n;
            }
        };
}
