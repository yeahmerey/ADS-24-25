#include <bits/stdc++.h>
using namespace std;

vector<int> era(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }
    vector <int> result ;
    for(int p = 2 ; p <= n ; ++p ){
        if(primes[p]){
            result.push_back(p);
        }
    }
    return result ;
}
int main(){
    int n = 80000 ;
    int k ; cin >> k ;
    vector <int> primes = era(n) ;
    for(int i = 0 ; i < primes.size() ; i ++){
        cout << primes[k-1] ;
        break ;
    }
    return  0;
}