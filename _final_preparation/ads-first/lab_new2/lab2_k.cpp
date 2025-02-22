#include <bits/stdc++.h>
using namespace std;

struct node{
    char val ;
    int cnt ;
    node * next  ;
    node * prev ;
    node(char x){
        val = x ;
        cnt = 1 ;
        prev = next = nullptr ;
    }
};

struct ll{
private :
    node * head ;
    node * tail ;
    int len ;
public:
    ll(){
        head = tail = nullptr ;
        len = 0 ;
    }
    node * find(char x){
        node * tr = head ;
        while(tr!=NULL){
            if(tr->val == x){
                return tr ;
            }
            tr = tr->next ;
        }
        return nullptr ;
    }
    void push(char x){
        node * n = new node(x) ;
        if(head == NULL){
            head = tail = n ;
        }
        else{
            node * a = find(x) ;
            if(a == nullptr){
                tail->next = n ;
                n->prev = tail ;
                tail = n;
            }
            else{
                a->cnt ++;
            }
        }
        len++ ;
    }
    void print(){
        node * main = head ;
        while(main!=nullptr){
            if(main->cnt == 1){
                cout << main -> val << " " ;
                return ;
            }
            main = main->next ;
        }
        cout << "-1" << " " ;
    }
    void clear(){
        node * tr = head;
        while(tr!=NULL){
            node * main = tr ;
            tr = tr->next  ;
            delete main ;
        }
        head = tail = nullptr ;
        len = 0 ;
    }
} ;
int main(){
    ll l1 ;
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ; char c ;
        for(int i = 0 ; i < n ; i ++){
            cin >> c ;
            l1.push(c) ;
            l1.print() ;
        }
        cout << endl ;
        l1.clear() ;
    }
}