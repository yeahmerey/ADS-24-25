#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[] , int low , int high , int x){
    while(low <= high){
        int mid = low + (high - low) / 2 ; 
        if(arr[mid] == x){
            return mid ;
        }
        if(arr[mid] < x){
            low = mid + 1 ;
        }
        else{
            high = mid -1 ; 
        }
        return -1; 
    }
}