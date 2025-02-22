#include <bits/stdc++.h>
using namespace std;
int main(){
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        deque <int> dq ;
        for(int i = n ; i > 0 ; --i){
            dq.push_front(i);
            for(int j = 0 ; j < i ; j ++){
                dq.push_front(dq.back()) ;
                dq.pop_back() ;
            }
        }
        for(int i = 0 ; i < n ; i ++){
            cout << dq[i] << " " ;
        }
        cout << endl ;
    }
}