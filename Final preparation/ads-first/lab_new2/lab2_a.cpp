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
public:
    ll(){
        head = tail = nullptr ;
        len = 0 ;
    }
    void push_back(int x){
        node * n = new node(x) ;
        len++ ;
        if(head == nullptr){
            head = tail = n ;
        }
        else{
            tail -> next = n ;
            n -> prev = tail ;
            tail = n ;
        }
    }
    void findNear(int m){
        node * cur = head ;
        int index = 0  , mnind = 0 ;
        int mx_distance = 1000; int distance ;
        while(cur != nullptr){
            distance = abs(m - cur->val);
            if(distance < mx_distance){
                mx_distance = distance ;
                mnind = index;
            }
            index ++ ;
            cur = cur->next ;
        }
        cout <<  mnind ;
    }
};
int main(){
    int n ; cin >> n ; ll l1 ;
    for(int i = 0 ; i < n ; i ++){
        int t ; cin >> t ;
        l1.push_back(t) ;
    }
    int m ; cin >> m ;
    l1.findNear(m);
}