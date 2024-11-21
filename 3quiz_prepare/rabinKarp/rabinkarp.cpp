#include <bits/stdc++.h>
using namespace std;

const int t = 256 ; //size of alphabet , in our case ASCII
const int w = 1283; //is prime ; 

void rabin_karp_algrthm(string text , string pattern){
    int tlen = text.length() ;  // text lenght
    int plen = pattern.length() ;  //pattern lenght 
    int c = 1 , i = 0  ;
    int hash_p = 0 , hash = 0 ; // it is using to hash_p(hash value of pattern) and hash_0
    //calculate pattern and first window of text : 
    while(i < plen){
        hash_p = (hash_p * t + pattern[i] ) % w ; 
        hash = (hash * t + text[i]) % w ; 
        i++ ; 
    } 
    //calculate (t^(plen-1)) % w
    for(int i = 1 ; i <= plen - 1 ; i++){
        c = (c * t)%w ; 
    }
    int flag ; 
    i = 0 ; 
    while(i <= tlen - plen){
        if(hash_p == hash){//проверяем хэши каждый строка . 
            flag = 1 ; //если равны то сразу чекаем символьно , так как есть коллизий
            for(int j = 0 ; j < plen ; j ++){
                if(pattern[j] == text[i+j]){
                    continue ; 
                }
                else{
                    flag = 0 ; 
                    break ; 
                }
            }
            if(flag == 1) cout << "Found at ind : " <<  i << endl ; 
        }
        //calcultae hash value of next window
        //hash_i+1 = t * {hash_i - text[i] * t^(plen-1) + text[i + plen]}
        if(i < tlen-plen){
            hash = ((t * (hash-text[i] * c)) + text[i + plen]) % w ; 
            if(hash < 0){
                hash = hash + w ; 
            }
        }
        i++ ; 
    }
}
int main(){
    string text = "ababcdabcd" ; 
    string pattern = "abc" ; 
    rabin_karp_algrthm(text , pattern) ;
    return 0 ; 
}