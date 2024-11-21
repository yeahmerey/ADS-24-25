#include <bits/stdc++.h>
using namespace std; 
int partition(vector<int>& arr , int low , int high){
    int pivot = arr[high]; 
    int i = low - 1 ; 
    for(int j = low ; j < high ; j ++ ){
        if(arr[j] <= pivot){
            i++ ; 
            swap(arr[i] , arr[j]) ; 
        }
    }
    swap(arr[i + 1] , arr[high]); 
    return i + 1;  
}
void quickSort(vector<int>& arr , int low , int high){
    if(low < high){
        int pivot = partition(arr , low , high) ;
        quickSort(arr , low , pivot-1) ;
        quickSort(arr , pi+ 1 , high) ;
    }
}