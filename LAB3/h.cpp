#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int binary_search(int x, vector<int>& v){
    int l = 0, r = v.size()-1;
    while(l<=r){
        int mid = l+ (r-l)/2;
        if(v[mid] == x){
            return mid;
        }
        else if(v[mid]<x){
            l = mid+1;
        } 
        else r = mid -1;
    }
    return l;
}

int main() 
{ 
    int n, m; cin >> n >> m;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        sum+=x;
        v[i] = sum;
    }
    while(m--){
        int t; cin >> t;
        cout << binary_search(t, v)+1 << endl;
    }

}