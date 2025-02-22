#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p = 31, C = 1e9 + 7;
int occur(string s, string t){
    vector<ull> p_pow(max(s.size(), t.size()));
    int res = 0;
    p_pow[0] = 1;
    for(int i = 1; i < p_pow.size(); i++){
        p_pow[i] = p_pow[i-1] * p;
    }

    vector<ull> h(t.size());
    for(int i = 0; i < t.size(); i++){
        h[i] = (t[i]-47) * p_pow[i];
        if(i) h[i] = h[i] + h[i-1];
    }

    ull h_s = 0;
    for(int i = 0; i < s.size(); i++){
        h_s  = h_s + (s[i] -47) * p_pow[i]; 
    }
    for(int i = 0; i + s.size() - 1< t.size(); i++){
        ull curH = h[i+s.size()-1];
        if(i) curH -= h[i-1];
        // if(i) h_s = h_s *p_pow[i]%C;
        if(curH == h_s *p_pow[i]){
            res++;
        }
    }
    return res;
}

int main(){
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        string t = s.substr(l-1, r-l+1);
        cout << occur(t, s)<<endl;
    }
    
}