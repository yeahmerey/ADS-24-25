#include <iostream>
#include <map>
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
    int n; cin >> n;
    map <string, string> nick;
    for (int i = 0; i < n; i++) {
        string s1; cin >> s1;
        string s2; cin >> s2;
        bool found = false;
        for (auto it = nick.begin(); it != nick.end(); it++) {
            if (it->second == s1) {
                nick[it->first] = s2;
                found = true;
                break;
            }
        }
        if (!found)
            nick[s1] = s2;
    }
    cout << nick.size() << "\n";
    for (auto it = nick.begin(); it != nick.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}