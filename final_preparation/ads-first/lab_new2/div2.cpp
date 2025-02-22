#include <bits/stdc++.h>
using namespace std;
int main(){
    int t ; cin >> t ; 
    while(t--){
        int n , m ; cin >> n >> m ; int mind ; 
        vector <int> a(n) ; int min = 1000 ; 
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i] ; 
            if(a[i] < min) min = a[i] ; mind = i ; 
        }
        int sum = 1 ; int cnt = 0 ; 
        for(int i = 0 ; i < n ; i ++){
            if(i != mind){
                sum *=a[i] ;
            }
            for(int i = 0 ; i <= 100 ; i ++){
                if((sum * min )%m != 0){
                    min++;
                    cnt++ ;  
                }
                else{
                    break ; 
                }
            }

        }
        cout << cnt ; 
    }
}