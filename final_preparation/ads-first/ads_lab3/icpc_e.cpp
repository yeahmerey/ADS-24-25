#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m ; cin >> n >> m ; int a[n] ; int ind = 0 ; int max = -10 ; 
    for(int i = 0 ; i < n ;i ++){
        cin >> a[i] ; 
        if(a[i] > max){max= a[i] ; ind = i ; }
    }
    a[ind]+=m ; 
    cout << a[ind] ; 
}