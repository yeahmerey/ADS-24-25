#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() { 
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int k; cin >> k;
    while(k--){
        int p; cin >> p;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] <= p){
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        int sum = 0, cnt = 0;
        for(int i = 0; i < l; i++){
            sum += v[i];
            cnt++;
        }
        cout << cnt << " " << sum << endl;
    }
}
//1 2 2 6 7 8 9