#include <bits/stdc++.h>
using namespace std;

void naive_algorithm(string text , string pattern){
    int n = text.length();
    int m = pattern.length() ; 
    int i , j ; 
    for(i = 0 ; i <= n - m ; i++){
        for(j = 0 ; j < m ; j ++){
            if(text[i + j] != pattern[j])
                break; 
        }
        if(j == m){
            cout << "Found at index " << i << endl ; 
        }
    } 
}
int main(){
    string pattern , text ;
    text = "I'm a coder, competitive coder!!" ; 
    pattern = "coder" ; 
    naive_algorithm(text , pattern) ; 
    return 0; 
}