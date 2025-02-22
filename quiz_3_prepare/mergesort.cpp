#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr , int left , int mid , int right){
    int n = mid - left + 1 ; 
    int m = right - mid ; 
    vector<int> leftSide(n); 
    vector<int> rightSide(m); 
    for(int i = 0 ; i < n ; i ++){
        leftSide = arr[left + i] ;
    }
    for(int i = 0 ; i < m ; i ++){
        rightSide = arr[mid + 1 + i] ; 
    }
    int i = 0 , j = 0 , main = left ;
    while(i < n && j < m){
        if(leftSide[i] <= rightSide[j]){
            arr[main] = leftSide[i];
            i ++ ; 
        }
        else{
            arr[main] = rightSide[j]; 
            j++ ; 
        }
        main++; 
    }
    while(i < n){
        arr[main] = leftSide[i] ; 
        i ++ ; 
        main++; 
    }
    while(j < m){
        arr[main] = rightSide[j] ; 
        j++ ; 
        main++ ; 
    }
}
void mergeSort(vector<int>& arr , int left , int right){
    if(left < right){
        int mid = left + (right-left) / 2 ; 
        mergeSort(arr , left , mid) ; 
        mergeSort(arr, mid + 1 , right) ; 
        merge(arr , left , mid , right) ;
    }
}timecomplexity: O(nlogn) , sp.complxty = O(n); 