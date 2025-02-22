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

int main(){
    string s; cin >> s;
    int n; cin >> n;
    s[0] = tolower(s[0]);
    vector<string> v;
    int maxL = 1;
    while(n--){
        string c; cin >> c;
        c[0] = tolower(c[0]);
        string p = c + '#' + s;
        vector<int> pi = prefix_function(p);
        c[0] = toupper(c[0]);
        if(maxL < pi.back()){
            maxL = pi.back();
            v.clear();
            v.push_back(c);
        }else if(pi.back() == maxL){
            v.push_back(c);
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    }