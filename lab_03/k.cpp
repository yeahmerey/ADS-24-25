#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, k; cin >> n>> k;
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int l = 0, r = 0, sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= k) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
    cout << (len == INT_MAX ? 0 : len);
}
// 3  6 1 4 5 2
// 3 9 10 14 19 21
// 3 5 7
// 3 8 15