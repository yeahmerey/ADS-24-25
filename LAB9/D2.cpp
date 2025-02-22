#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool red[100000];
bool visited[100000];

int dfs (vector <vector <int> > &adj, vector <bool> &visited, vector <bool> &red, int v, int cnt, bool &reached) {
    if (red[v] == true) {
        reached = true;
        return cnt;
    }
    visited[v] = true;
    int res = INT_MAX;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            res = min(dfs(adj, visited, red, i, cnt + 1, reached), res);
        }
    }
    return res;
}

int bfs (vector <vector <int> > &adj, vector <bool> &visited, int v) {
    queue <int> q;
    int dist[adj.size()];
    q.push(v);
    dist[v] = 0;
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (red[u]) {
            return dist[u];
        }
        for (int i = 0; i < adj.size(); i++) {
            if (adj[u][i] == 1 && !visited[i]) {
                visited[i] = true;
                dist[i] = dist[u] + 1; 
                q.push(i);
                if (red[i]) {
                    return dist[i];
                }
            }
        }
    }
    return -1;
}

void search (vector <vector <int> > &adj, int v) {
    vector <bool> visited(adj.size(), false);
    bool reached = false;
    cout << bfs(adj, visited, v) << '\n';
}

int main() {
    int n, m, q; cin >> n >> m >> q;
    vector <vector <int> > adj(n, vector<int> (n, 0));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }
    while(q--) {
        int i, v; cin >> i >> v;
        if (i == 1)
            red[v - 1] = true;
        else {
            search(adj, v - 1);
        }
    }
}