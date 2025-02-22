#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = 1e20;
    while(l <= r) {
        ll mid = l + (r - l) / 2, cnt = 1, sum = 0;
        for(int i = 0; i < n; i++) {
            if(mid < sum + a[i]) {
                cnt++;
                sum = 0;
            }
            if(mid < a[i]) {
                cnt = k + 1;
            } 
            sum += a[i];
        }
        if(k < cnt) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;

}