#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() { 
  int n, k; cin >> n >> k;
  vector<int> res;
  int maxi;
  while(n--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1>> x2 >> y2;
    maxi = max(max(x1, y1), max(x2, y2));
    res.push_back(maxi);
  }
  sort(res.begin(), res.end());
  cout << res[k-1];
}