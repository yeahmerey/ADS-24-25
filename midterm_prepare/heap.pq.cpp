#include <bits/stdc++.h>
using namespace std;

struct hp{
    long long hs ; 
    void sift_up(long long pos){
        long long p = (pos-1)/ 2 ; 
        while(pos > 0 && val[p] > val[pos]){
            swap(val[p] , val[pos]); 
            pos = p ; 
            p = (pos-1) / 2 ;
        }
    }
    void sift_down(){
        val[0] = val[--hs]; 
        long long pos = 0 ; 
        while(2 * pos + 1 < hs){
            ll p1 = 2 * pos + 1 ; 
            ll p2 = 2 * pos + 2 ; 
            ll npos = pos ; 
            if(val[pos] > val[p1]){
                npos = p1 ;
            }
            if(p2 < hs && val[npos] > val[p2]){
                npos = p2 ; 
            }
            if(npos!=pos){
                swap(val[npos], val[pos]); 
                pos = npos; 
            }
            else{
                break ; 
            }
        }
    }
    public : 
    void add(ll v){
        val[hs++] = v ; 
        sift_up(hs-1); 
    }
    ll cut_min(){
        ll res = val[0]; 
        sift_down(); 
        return result ;
    }
    ll size(){
        return hs ; 
    }
}