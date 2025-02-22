#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin >> n ;
    string t ; cin >> t ;
    queue <int> q1 , q2 ;
    for(int i = 0 ; i < n ; i ++){
        if(t[i] == 'K'){q1.push(i); }
        else{q2.push(i); }
    }
    while(!q1.empty() and !q2.empty()){
        int fr1 = q1.front() ;
        int fr2 = q2.front() ;
        if(fr1 < fr2){
            q1.push(fr1+n) ;
            q1.pop() ; q2.pop() ;
        }
        else{
            q2.push(fr2+n);
            q1.pop() ; q2.pop() ;
        }
    }
    if(!q1.empty()){
        cout << "KATSURAGI" ;
    }
    else{
        cout << "SAKAYANAGI" ;
    }
}