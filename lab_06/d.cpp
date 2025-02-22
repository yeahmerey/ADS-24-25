#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check(int a[], int b[]) {
    if (a[2] == b[2]) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        else
            return a[1] < b[1];
    }
    else
        return a[2] < b[2];
}

int partition(int a[][3], int left, int right, int pivot[]) {
    while(left <= right) {
        while(check(a[left], pivot)) {
            left++;
        }
        while(check(pivot, a[right])) {
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

int partition2(int a[][3], int left, int right) {
    int pivot = right;
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (check(a[j], a[pivot])) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void QuickS(int a[][3], int left, int right) {
    if (left >= right) {
        return;
    }
    // int pivot[] = a[(left + right)/2];
    //int index = partition(a, left, right, a[(left + right)/2]);
    int index = partition2(a, left, right);
    QuickS(a, left, index - 1);
    QuickS(a, index + 1, right);
}

int main() {
    int n; cin >> n;
    int dates[n][3];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int day = stoi(s.substr(0, 2));
        int month = stoi(s.substr(3, 2));
        int year = stoi(s.substr(6, 4));
        dates[i][0] = day;
        dates[i][1] = month;
        dates[i][2] = year;
    }
    QuickS(dates, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (dates[i][0] < 10)
            cout << "0";
        cout << dates[i][0] << "-";

        if (dates[i][1] < 10)
            cout << "0";
        cout << dates[i][1] << "-" << dates[i][2] << "\n";
    }

}