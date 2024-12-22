#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ;
    node * prev ;
    node * next ;

    node(int x){
        val = x;
        next = prev = NULL ;
    }
};
struct ll{
private :
    node * head ;
    node * tail ;
    int len ;
public :
    ll(){
        head = tail = NULL ;
        len = 0 ;
    }
    void push_back(int n){
        node * m = new node(n) ;
        len++;
        if(tail == NULL){
            tail = head = m ;
        }
        else{
            tail->next = m ;
            m->prev = tail ;
            tail = m ;
        }
    }
    void print(){
        if(len == 0){
            cout <<  "-1";
        }
        node * cur = head ;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur = cur->next ;
        }
    }
    void insert(int a , int p){
        node * n = new node(a);
        node * temp = head;
        node * cur = head;
        if(p == 0){
            n->next = head ;
            head->prev = n ;
            head = n ;
        }
        else if(p == len){
            tail->next = n ;
            n->prev = tail  ;
            tail = n ;
        }
        else{
            for(int i = 0 ; i < p-1 ; i ++){
                temp = temp->next ;
                cur = temp->next ;
            }
            temp->next = n ;
            n->prev = temp ;
            n->next = cur ;
            cur->prev = n ;
        }
        len++;
    }
    void remove(int p){
        if(p == 0){
            node * cur = head;
            head = cur->next ;
            cur = nullptr ;
        }
        else if(p == len-1){
            node * cur = tail->prev ;
            cur->next = nullptr ;
        }
        else{
            node * cur = head ;
            for(int i = 0 ; i < p ; i ++){
                cur = cur->next ;
            }
            cur->prev->next = cur->next ;
            cur->next->prev = cur->prev ;
            delete cur ;
        }
        len--;
    }
    void reverse(){
        node * cur = head ;
        node * temp = nullptr ;
        while(cur!= nullptr){
            temp = cur->next ;
            cur->next = cur->prev ;
            cur->prev = temp ;
            cur = temp;
        }
        temp = head;
        head = tail ;
        tail = temp ;
    }
    void replace(int p1, int p2) {
        node* cur = head;
        for (int i = 0; i < p1; i++) {
            cur = cur->next;
        }
        node * cur1= head ;
        for (int i = 0; i < p2; i++) {
            cur1 = cur1->next;
        }
        node* cur_prev = cur->prev;
        node* cur1_prev = cur1->prev;
        node* cur_next = cur->next;
        node* cur1_next = cur1->next;
        if (cur1->next == cur) {
            if (cur1_prev!=NULL){cur1_prev->next = cur;}
            if (cur_next!=NULL){ cur_next->prev = cur1;}

            cur->prev = cur1_prev;
            cur->next = cur1;
            cur1->prev = cur;
            cur1->next = cur_next;
        }
        else if (cur->next == cur1) {
            if (cur_prev!=NULL) {cur_prev->next = cur1;}
            if (cur1_next!=NULL) {cur1_next->prev = cur;}
            cur1->prev = cur_prev;
            cur1->next = cur;
            cur->prev = cur1;
            cur->next = cur1_next;
        }else {
            if (cur_prev != NULL) cur_prev->next = cur1;
            if (cur_next != NULL) cur_next->prev = cur1;
            if (cur1_prev != NULL) cur1_prev->next = cur;
            if (cur1_next != NULL) cur1_next->prev = cur;

            cur->next = cur1_next;
            cur->prev = cur1_prev;
            cur1->next = cur_next;
            cur1->prev = cur_prev;
        }
        if (p1 == 0) head = cur1;
        if (p2 == 0) head = cur;

        if (cur->next == nullptr) tail = cur;
        if (cur1->next == nullptr) tail = cur1;
    }
    void to_left(int x){
        if(len == 0 or len%x == 0) return ;
        x = x%len ;
        node * temp = head ;
        for(int i = 0 ; i < x-1 ; i++ ){
            temp = temp->next ;
        }
        node * nhead = temp->next ;
        temp->next = nullptr ;
        node * tail = nhead ;

}

};
int main(){
    int n ; cin >> n ; ll l1 ; int m ;
    for(int i = 0 ; i < n ; i ++){
        cin >> m ;
        l1.push_back(m) ;
    }
    l1.print() ;
    l1.replace (0 , 1) ;
    l1.print() ;

}