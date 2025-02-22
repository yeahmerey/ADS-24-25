#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, pair <int, int> > > g;
vector<int> p;

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
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    p.resize(n);
    int both = min(x, y);
    while(m--) {
        string s; cin >> s;
        int a, b, c; 
        cin >> a >> b >> c;
        a--; b--;
        if(s == "both") {
            c *= both;
        } else if(s == "big") {
            c *= x;
        } else {
            c *= y;
        }
        g.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(g.begin(), g.end());

    for(int i = 0; i < n; i++) {
        p[i] = i;
    }

    int total = 0;
    for(int i = 0; i < g.size(); i++) {
        int a = g[i].second.first;
        int b = g[i].second.second;
        int c = g[i].first;
        if(dsuGet(a) != dsuGet(b)) {
            total += c;
            dsuUnite(a, b);
        }
    }
    cout << total << "\n";

    return 0;
}