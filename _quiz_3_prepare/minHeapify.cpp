#include <bits/stdc++.h>
using namespace std ; 

void minHeapify(vector<int>& heap , int n , int i){
    int minn = i ; 
    int left = 2 * i + 1 ; 
    int right = 2 * 2  + 2 ; 
    if(left < n && heap[left] < heap[minn]){
        minn = left ; 
    }
    if(right  < n && heap[right] < heap[minn]){
        minn = right ; 
    }
    if(minn != i ){
        swap(heap[i] , heap[minn]); 
        minHeapify(heap , n , minn); 
    }
} 
