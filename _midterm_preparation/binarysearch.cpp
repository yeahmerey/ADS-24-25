#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[] , int l , int r , int x){
    while(l <= r){
        int mid = l + (r - l) / 2; 
        if(arr[mid] == target){
            return mid ; 
        }
        if(arr[mid] > target){
            return mid ; 
        }
        else{
            left = mid + 1 ;
        }
    }
}