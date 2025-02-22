#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p = 31, C = 1e9 + 7;

char toChar(ull cur, ull pre, int pos){    
    cur -= pre;
    cur /= pow(2,pos);
    return char(cur+97);
}

int main(){
    int n; cin >> n;
    vector<ull> v(n);
    for(int i = 0; i < n;i++){
        cin >> v[i];
        if(i){
            cout << toChar(v[i], v[i-1], i);
        }else{  
            cout << toChar(v[i], 0, 0);
        }
    }
    
}