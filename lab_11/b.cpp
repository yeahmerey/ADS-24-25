#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector <int> v(n);
    int min = 1e9, index = -1, sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(min > v[i]) {
            min = v[i];
        }
        sum += v[i];
    }

    sum -= min;
    cout << (n - 1) * min + sum << "\n";

    return 0;
} 