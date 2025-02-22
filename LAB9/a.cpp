#include <bits/stdc++.h>

using namespace std;

int solve(string s, string t) {
	int n = s.size(), m = t.size();
	int i = 0, cnt = 0;
	bool flag = false;
	while(i < n){
		int j = i, k = 0, cnt = 1;
		while(k < m && s[j] == t[k]){
			if(k == m-1){
				flag = true;
				break;
			}
			j = (j+1) % n;
			if(j==0) cnt++;
			k++;
		}
		if(flag) return cnt;
		i++;
	}
	return -1;
}


int main() {
    string s, t;
    cin >> s >> t;

    cout << solve(s, t);

}