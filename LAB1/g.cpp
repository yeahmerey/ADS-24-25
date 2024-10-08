#include <bits/stdc++.h>
using namespace std;

vector <bool> era( 80000 , true) ;

int main(){
    vector <int> v1 ;
    int n ; cin >> n ;
    v1.push_back(0) ;
    for(int i = 2 ; i <= 10000 ; i ++){
        if(era[i]){
            v1.push_back(i) ;
            int l = i * i ;
            while(l < 10000){
                era[l] = false ;
                l += i ;
            }
        }
    }
    cout << v1[v1[n]] ;
}



//1 2 3 4 5   6   7
//2 3 5 7 11  13  17

//1 2 3 4 5