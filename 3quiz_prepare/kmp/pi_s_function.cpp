#include <bits/stdc++.h>
using namespace std;

int pi(string s){
    int n = s.size() ; 
    for(int suffix_len = n - 1 ; suffix_len > 0 ; suffix_len --){
        string suffix = s.substr(n - suffix_len , suffix_len) ; 
        string prefix_same_len = s.substr(0 , suffix_len);
        if(suffix == prefix_same_len){
            return suffix_len ; 
        }
    }
    return  0 ; 
}