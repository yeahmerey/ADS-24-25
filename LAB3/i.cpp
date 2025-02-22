#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() { 
  int n; cin >> n; 
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  int target; cin >> target;
  int l = 0, r = n-1;
  while(l <= r){
    int mid = l+(r-l) / 2;
    if(v[mid] == target){
      cout << "Yes"; 
      return 0;
    }else if(v[mid]>target){
      r = mid-1;
    }else{
      l = mid+1;
    }
  }
  cout << "No";
}