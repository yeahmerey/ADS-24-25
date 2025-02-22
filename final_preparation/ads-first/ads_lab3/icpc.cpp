#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin >> n ; int ans ; 
    int uts = 6 , time = 11 ; 
    if(n < 0){
        int distance = uts - n ;
        if(time - distance < 0){
            ans = 24 - abs(time-distance) ;
        }
        else{
            ans = time - distance ; 
        } 
    }
    else{
        if(n < uts){
            ans = time - (uts - n);
        }
        else{
            ans = time + (n - uts); 
        }
    }
    //-12 
    if(ans < 10){
        cout << "0" << ans << ":00" ; 
    }
    else{
        cout << ans << ":00" ; 
    }
}