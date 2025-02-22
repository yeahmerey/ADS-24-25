#include <bits/stdc++.h>
using namespace std; 

#define d 10 
void rabinkarp(char pattern[] , char text[] , int q){
    int n = strlen(text) ;  //size of text 
    int m = strlen(pattern) ;  // size of pattern
    int i , j ; 
    int p = 0 ; //pattern hash value 
    int t = 0 ; //text hash value
    int h = 1 ; 
    //calculate max t^m-1 :
    for(i = 0 ; i < m-1 ; i ++){
        h = (h * d) % q ;  
    }
    //calculate hash value of pattern and text's first window ; 
    for(i = 0 ; i < m ; i ++){
        p = (d * p + pattern[i]) % q ; 
        t = (d * t + text[i]) % q ; 
    }
    //find match
    for(int i = 0 ; i <= n - m ; i++){
        if(p == t){
            for(j = 0 ; j < m ; j++){
                if(text[i+j] != pattern[j]){
                    break ; 
                }
            }
            if(j == m ){
                cout << "Pattern is found at position : " << i + 1 << endl ; 
            }
        }
        if(i < n - m){
            t = (d * (t - text[i] * h) + text[i + m]) % q ; 
            if(t < 0){
                t = (t + q) ; 
            }
        }
    }
}
int main(){
    char text[] = "ABCCDDAEFG" ; 
    char pattern[] = "CDD" ; 
    int q = 13 ; 
    rabinkarp(pattern , text, q) ; 
}