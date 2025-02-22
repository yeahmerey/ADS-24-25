#include <bits/stdc++.h>
using namespace std;
int main(){
    string s ; cin >> s;
    if(s.size() % 2 == 1){
        cout << "NO" ;
    }
    else {
        for(int t = 0 ; t <= 100 ; t++) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == s[i + 1]) {
                    s.erase(i, 2);
                }
            }
        }
        if(s.empty()){
            cout << "YES" ;
        }
        else{
            cout << "NO" ;
        }
    }
}