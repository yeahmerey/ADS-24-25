#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin >> n ; vector <int> a(n) ;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i] ;
    }
    stack <int> main ; main.push(-1) ;
    for(int i = 0 ; i < n ; i ++){
        while(main.top() > a[i]){
            main.pop() ;
        }
        cout << main.top() << " " ;
        main.push(a[i]) ;
    }
}