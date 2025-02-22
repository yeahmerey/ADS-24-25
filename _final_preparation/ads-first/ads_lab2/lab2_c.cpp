#include <bits/stdc++.h>
using namespace std;

#define n0 NULL ; 

struct node {
    int val ; 
    node* next ; 
    node* prev ; 
    node(int x){
        val = x ; 
        prev = next = NULL ; 
    }
};
struct dll {
    private :
        node* head ; 
        node* tail ; 
    public: 
        dll(){
            head = tail = NULL ; 
        }
        void push(int x){
            node* n = new node(x) ; 
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
            if(head == NULL)return ; 
            node* cur = head ; 
            int ind = 1 ; 
            while(cur != NULL){
                if(ind%2 == 0){
                    node* temp = cur ;
                    if(temp->prev !=NULL) temp->prev->next = temp->next ; 
                    if(temp->next != NULL) temp->next->prev = temp->prev ; 
                    if(temp == head) head = temp->next ;
                    if(temp == tail) tail = temp->prev ; 
                    cur = cur->next ; 
                    delete temp ; 
                }
                else{
                    cur = cur->next ; 
                }
                ind++ ; 
            }
        }
        void print(){
            node* cur = head;  
            while(cur!=NULL){
                cout << cur->val << " " ; 
                cur = cur->next ;
            }
            cout << endl ; 
        }
};
int main(){
    dll d1 ;
    int n, t ; cin >> n ; 
    for(int i = 0 ; i < n ; i++){
        cin >> t; 
        d1.push(t) ; 
    } 
    d1.remove() ;
    d1.print()  ;  

}