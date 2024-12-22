#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(const string& pattern , vector<int>& lps){
    int lenght = 0 ; 
    lps[0] = 0 ; 
    int i = 1; 
    while(i < pattern.length()){
        if(pattern[i] == pattern[lenght]){
            lenght++; 
            lps[i] = lenght; 
            i++; 
        }
        else{
            if(lenght != 0 ){
                lenght = lps[lenght-1] ;
            }
            else{
                lps[i] = 0 ; 
                i ++ ; 
            }
        }
    }
}

void KMPSearch(const string& text , const string& pattern){
    int M = pattern.length() ; 
    int N = text.length() ;
    vector<int> lps(M) ;
    computeLPSArray(pattern , lps) ;

    int i = 0 ; int j = 0 ; 
    while(i < N){
        if(pattern[j] == text[i]){
            i++;
            j++; 
        }
        if(j == M){
            cout << "Fount pattern at index : " << i - j << endl ; 
            j = lps[j-1]; 
        }
        else if(i < N && pattern[j] != text[i]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++; 
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}