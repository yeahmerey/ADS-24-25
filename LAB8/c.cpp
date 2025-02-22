#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p = 31, C = 1e9 + 7;
void occur(string s, string t, vector<bool> &v){
    vector<ull> p_pow(max(s.size(), t.size()));
    vector<int> res;
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
        if(curH == h_s * p_pow[i]){
            for(int j = i; j <= i+ s.size()-1; j++){
                v[j] = true;
            }
            // cout << i << " " << endl;
        }
    }
}

int main(){
    string s; cin >> s;
    int n; cin >> n;
    vector<bool> v(s.size());
    while(n--){
        string tape; cin >> tape;
        occur(tape, s, v);
    }
    for(int i = 0; i < v.size();i++){
        // cout << v[i] << " ";
    }
    for(int i = 0; i < v.size(); i++){
        // cout << v[i] << " ";
        if(!v[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    



}