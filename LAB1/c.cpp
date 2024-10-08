#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1 , s2 ; cin >> s1 >> s2 ; string ans1 = "", ans2 = ""  ;
    for(int i = 0 ; i < s1.size() ; i ++){
        if(s1[i] == '#')ans1.pop_back();
        else ans1+=s1[i] ;
    }
    for(int i = 0 ; i < s2.size() ; i++){
        if(s2[i] == '#') ans2.pop_back() ;
        else ans2+=s2[i] ;
    }
    if(ans1 == ans2)cout << "Yes"; else cout << "No" ;
}