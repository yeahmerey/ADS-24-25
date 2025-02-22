#include <iostream>
#include <algorithm>

using namespace std;

int partition(int a[], int left, int right, int pivot) {
    while(left <= right) {
        while(a[left] < pivot) {
            left++;
        }
        while(a[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        } 
    }
    return left;
}

void QuickS(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = a[(left + right)/2];
    int index = partition(a, left, right, pivot);
    QuickS(a, left, index - 1);
    QuickS(a, index, right);
}

int main() {
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    QuickS(a, 0, n - 1);
    QuickS(b, 0, m - 1);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}