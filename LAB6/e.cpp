#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition (int a[], int left, int right) {
    int pivot = right;
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (a[j] <= a[pivot]) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void QuickS (int a[], int left, int right) {
    if (left < right) {
        int index = partition(a, left, right);
        QuickS(a, left, index  - 1);
        QuickS(a, index + 1, right);
    }
}

int main() {
    int n, m; cin >> n >> m;
    int arr[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // int a; cin >> a;
            cin >> arr[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        QuickS(arr[i], 0, n - 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}