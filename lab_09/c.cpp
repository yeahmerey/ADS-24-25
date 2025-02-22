#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i-1];

        while(j > 0 && s[i] != s[j]){
            j = p[j-1];
        } 

        if(s[i] == s[j]) j++;

        p[i] = j;
    }
    return p;
}

vector<int> KMP(string pat, string txt){
    vector<int> res;
    string s = pat + '#' + txt;
    vector<int> p = prefix_function(s);
    for(int i = pat.size()+1; i < s.size();i++){
        if(p[i] == pat.size()){
            res.push_back(i - 2 * pat.size());
        }
    }
    return res;
}


int main(){
    // string pat, txt; cin >> pat >> txt;
    // txt+=txt;
    // vector<int> v = KMP(pat, txt);

    // cout << (v.size()? v[0]: -1);
    
    string s;
    cin >> s;

    vector<int> v = prefix_function(s);

    for(int i = 0; i < s.size(); i++){
        cout << v[i] << " ";
    }
}