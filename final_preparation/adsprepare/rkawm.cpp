#include <bits/stdc++.h>
using namespace std; 

//d is the number of characters in the input alphabet
// why we choose 256? because , in ascii 256 character . 
#define d 256 

/*
    pat - > pattern ;
    txt - > main text;  
    q - A prime number;
    if q is big prime , it is do minimize collision 
 */

void search(char pat[] , char txt[] , int q){
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i , j ; 
    int p = 0 ;  // hash value of pattern ; 
    int t = 0 ;  //hash value of txt 
    int h = 1 ;  

    // канша подстрока болу мумкин: 
    for(int i = 0 ; i < M-1 ; i ++){
        h = (h * d) % q ; 
    }
    /*
     calculate the hash value of pattern
     and first window of text 
    */
    for(int i = 0 ; i < M ; i++){
        p = (d * p + pat[i]) % q ; 
        t = (d * t + txt[i]) % q ; 
    }
    //перемещаем шаблон друг за другом : 
    for(int i = 0 ; i <= N - M ; i ++){
        /*
            Check the hash values of current window
            of text and pattern , if the hash values match
            then only check for characters one by one
         */
        if(p == t){
            //check for characters one by one : 
            for(j = 0 ; j < M ; j ++){
                if(txt[i + j] != pat[j]){
                    break ; 
                }
            }
            /*
            if p == t and pat[0...M-1] = txt[i , i + 1 ,...i + M -1]
            */
            if(j == M){
                cout << "Pattern found at index" << i << endl ; 
            }
        }
        /*
        calculate hash value for next window of text :
        remove leading digit , add trailing digit
        */
        if(i < N-M){
            t = (d * (t - txt[i] * h) + txt[i + M]) % q ; 
            if( t < 0 ){
                t = t + q ; 
            }
        }
    }
}

/* Driver code */

int main()
{
    char txt[] = "MereyMereyYerem" ; 
    char pat[] = "Merey" ; 
    int q = INT_MAX ; 
    // q is as big because it is avoid the collision : 
    search(pat , txt , q) ;
    return 0 ; 
};