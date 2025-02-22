#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> merge(vector<string> left, vector<string> right) {
    vector<string> result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l].size() > right[r].size()) {
            result.push_back(right[r]);
            r++;
        } else {
            result.push_back(left[l]);
            l++;
        }
    }
    while(l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while(r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    return result;
}

vector <string> mergeSort(vector <string> v, int l, int r) {
    if(l == r) {
        vector <string> result;
        result.push_back(v[l]);
        return result;
    }
    int mid = l + (r - l) / 2;
    vector <string> left = mergeSort(v, l, mid);
    vector <string> right = mergeSort(v, mid + 1, r);
    return merge(left, right);
}

int main() {
    string tmp; 
    getline(cin, tmp);
    int t = stoi(tmp);
    vector <vector <string> > v;

    while(t--) {
        string s; 
        getline(cin, s);
        s += ' ';
        vector <string> v1;
        string str = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                v1.push_back(str);
                str = "";
            } else {
                str += s[i];
            }
        }
        v1 = mergeSort(v1, 0, v1.size() - 1);
        v.push_back(v1);
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}