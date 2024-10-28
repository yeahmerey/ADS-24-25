#include <bits/stdc++.h>
using namespace std;

void bubSort(vector<int>& a){
    int n = a.size(); 
    bool swaps ; 
    for(int i = 0 ... i < n-1){
        swaps = false;
        for(int j =0 ... j<n-i-1){
            if(a[j]>a[j+1]){
                swap(arr[j],arr[j+1]);
                swaps = true; 
            }
        }
    }if(!swaps) break ; 
}