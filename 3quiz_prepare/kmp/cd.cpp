#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int k = n - 2;
        int b = -1, c = -1; 
        bool check = false; 

        for (int i = 0; i < n; i++) {
            if(k % a[i] == 0){
                for (int j = i; j < n; j++) {
                    if(k % a[j] == 0){
                        b = a[i] ; 
                        c = a[j]; 
                        break ; 
                    }
                }
            }
        }
        cout << b << " " << c << endl;
    }

    return 0;
}