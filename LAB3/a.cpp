#include <bits/stdc++.h>

using namespace std;

int binarySearchIncr(int arr[], int l, int r, int target) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            r = mid - 1; 
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int binarySearchDecr(int arr[], int l, int r, int target) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            l = mid + 1;
        } else {
            r = mid -1;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    int arr[t];
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < n; j++) {
            if(j % 2 == 1) {
                int ind = binarySearchIncr(a[j], 0, m - 1, arr[i]);
                if(ind != -1) {
                    cout << j << " " << ind << endl;
                    break;
                } else if( j + 1 == n) {
                    cout << ind << endl;
                    break;
                }
            } else {
                int ind = binarySearchDecr(a[j], 0, m - 1, arr[i]);
                if(ind != -1) {
                    cout << j << " " << ind << endl;
                    break;
                } else if(j + 1 == n) {
                    cout << ind << endl;
                    break;
                }
            }
        }
    }  
}