#include <bits/stdc++.h>
using namespace std;

int bs(int x , int * a , int n){
    int l = 0 ; 
    int r = n - 1 ; 
    int result = -1 ; 
    while(l <= r){
        int m = l + (r-l) / 2 ; 
        if(a[m] == x){
            result = m ; 
            break ; 
        }
        if(a[m] < x){
            l = m + 1 ; 
        }
        else{
            r = m - 1; 
        }
    }
    return result
}

int main(){
    int a[] = {1 , 23 , 32, 42,43,45} ; 
    int n = sizeof(a) / sizeof(a[0]); 
    sort(a , a+n); 
    int x ; 
    cin >> x;  
    cout << bs(x , a , n) << endl ;  
}