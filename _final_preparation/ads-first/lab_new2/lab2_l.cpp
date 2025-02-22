#include <bits/stdc++.h>
using namespace std;

struct node{
    int val ;
    int sum ;
    node * next ;
    node * prev ;
    node(int x){
        val = x;
        sum = x;
        next = prev = nullptr ;
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
        void push(int x){
            node * n = new node(x) ;
            if(head == nullptr){
                head = tail = n ;
                n->sum = x ;
            }
            else{
                tail ->next = n ;
                n ->prev = tail ;
                tail = n ;
                n->sum = max(n->prev->sum + n->sum , n->sum) ;
            }
            len ++ ;
        }
        int findMaxSum(){
            node * cur = head ;
            int mx = head -> sum ;
            while(cur!=nullptr){
                mx = max(mx , cur->sum);
                cur = cur->next ;
            }
            return mx ;
        }
};
int main(){
    ll l1 ; int n , t ; cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        cin >> t ;
        l1.push(t) ;
    }
    cout << l1.findMaxSum();
}