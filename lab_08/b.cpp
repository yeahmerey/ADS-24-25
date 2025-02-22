#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p = 31, C = 1e9 + 7;
vector<int> occur(string s, string t){
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
        if(curH == h_s *p_pow[i]){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    string s1, s2, t; cin >> s1 >> s2 >>t;
    vector<int> v1 = occur(t, s1), v2 = occur(t, s2);
    int cnt = 0;
    int i = 0, j = 0;
    // for(int i = 0; i < v2.size(); i++){
    //     cout << v2[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < v1.size(); i++){
    //     cout << v1[i] << " ";
    // }
    while(i < v1.size() && j < v2.size()){
        if(v1[i] == v2[j]){
            cnt++;
            i++; j++;
        }else if(v1[i] < v2[j]){
            i++;
        }else{
            j++;
        }
    }
    cout << cnt;
    



}