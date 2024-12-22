#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int t ; cin >> t ; 
    while(t--){
        ll n , k ; cin >> n >> k ; ll cnt = 0 ; 
        vector <int> a(n) ; ll sum = 0 ;  
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i] ;
            if(a[i] >= k ){
                sum+=a[i];
            } 
            else if(a[i] == 0){
                sum-=1; 
                cnt++ ; 
            }
        }
        cout << cnt << endl ; 
    }
}