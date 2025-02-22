#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    int diff = INT_MAX;
    map<pair<int,int>, int> m;
    for(int i = 1;i < n; i++){
        diff = min(diff, a[i]-a[i-1]);
        m[{a[i],a[i-1]}] = a[i]-a[i-1];
    }
	map<pair<int,int>, int> ::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if((*it).second == diff) {
            cout << (*it).first.second << " " << (*it).first.first << " ";
        }
    }
}