#include <bits/stdc++.h>
using namespace std;
//insertion sorts builds a s/ted arr one item at a time.each time we replacing to correct place to the cards; 
void ins_sort(int arr[] , int n){
    for(int i = 1; i <n ; i ++){
        int k = arr[i]; int j = i -1 ; 
        while(j>=0 && arr[j]>k){
            arr[j+1] = arr[j]; j = j -1; 
        }
        arr[j+1] = key ; 
    }
}