#include <bits/stdc++.h>
using namespace std;
#define d 10 
void rabinKarp(string text , string pattern , int q){
    int tlen = text.length(); 
    int plen = pattern.length(); 
    int i , j ;
    int p = 0 ; 
    int t = 0 ; 
    int h = 1 ; 
    //calc max t^(m-1) ; 
    for(i = 0 ; i < m - 1 ; i ++){
        h = (h * d) % q ; 
    }
    //calc hash value of pattern and text's first window :
    for(i = 0 ; i < m ; )

}