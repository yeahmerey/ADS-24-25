#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr , int n , int i){
    int large =  i; 
    int l = 2 * i  + 1 ; int r = 2 * i+2; 
    if(l < r && arr[l] > arr[large]) large = i ; 
    if(r < n && arr[r] > arr[large]) large = r ; 
    if(large != i ){
        swap(arr[i], arr[large]); 
        heapify(arr , n , large); 
    }
}
void hs(vector<int>& arr){
    int n = arr.size();for(i = n/2-1 ; i>=0;--){
        heapify(arr,n,i); 
    }
    for(int i = n-1 ;i > 0 ; i--){
        swap(arr[0],arr[i]); 
        heapify(arr,i,0); 
    }
}