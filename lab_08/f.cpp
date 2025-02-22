#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p = 31, C = 1e9 + 7;

vector<ull> getHash(string s, vector<ull> p_pow){
    vector<ull> hashes(s.size());
    for(int i =0; i < s.size(); i++){
        hashes[i] = (s[i]-'a'+1) * p_pow[i];
        if(i) hashes[i]+=hashes[i-1];
    }
    return hashes;
}

int main(){
    string s; cin >> s;
    vector<ull> p_pow(s.size());
    p_pow[0] = 1;

    for(int i = 1; i < p_pow.size(); i++){
        p_pow[i] = p_pow[i-1] *p;
    }

    vector<ull> pre_hash = getHash(s, p_pow);
    unordered_set<ull> st;
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            ull cur_hash = pre_hash[j];
            if(i) cur_hash -= pre_hash[i-1];
            cur_hash*= p_pow[s.size()-i-1];
            st.insert(cur_hash);
        }
    }
    cout << st.size();
    
}