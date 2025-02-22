#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int fun(const vector<int> &v, int k){
    int h = 0;
        if(k == 0) return INT_MAX;
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i] % k != 0)
            {
                h++;
            }
            h += (v[i] / k);
        }
        return h;
}

int main() 
{ 
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }   
    ll sum = 0;
        int mx = 0;
        for(int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            mx = max(mx, v[i]);
        }
        int l = sum / k, r = mx, ans;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            int ans = fun(v, mid);
            if(ans > k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        cout<< r;
    

}