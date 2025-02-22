#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long long, pair <int, int> > > g;
vector<int> p(1000001);

int dsuGet(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = dsuGet(p[v]);
}

void dsuUnite(int a, int b) {
	a = dsuGet(a);
	b = dsuGet(b);
	if (a != b) {
        p[a] = b;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    p.resize(n);

    while(q--) {
        int l, r;
        long long cost;
        cin >> l >> r >> cost;
        l--; r--;
        for(int i = l; i < r; i++) {
            for(int j = i + 1; j <= r; j++) {
                if(i != j) {
                    g.push_back(make_pair(cost, make_pair(i, j)));
                }
            }
        }
    }

    sort(g.begin(), g.end());

    for(int i = 0; i < n; i++) {
        p[i] = i;
    }

    long long total = 0;
    for(int i = 0; i < g.size(); i++) {
        long long cost = g[i].first;
        int a = g[i].second.first;
        int b = g[i].second.second;
        if(dsuGet(a) != dsuGet(b)) {
            total += cost;
            dsuUnite(a, b);
        }
    }
    cout << total << "\n";

    return 0;
}
