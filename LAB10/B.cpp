#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
vector <int> graph1(10001);
bool used[10001];

int main(){
    int n; 
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int k; 
            cin >> k;
            if (k == 1){
                graph[i].push_back(j);
            }
        }
    }

    int a;
    int b;
    cin >> a >> b;

    deque <int> d;
    d.push_back(a);
    used[a] = true;

    while (!d.empty()){
        int g = d.front();
        for (int i = 0; i < graph[g].size(); ++i){
            int num = graph[g][i];
            if (!used[num]){
                used[num] = true;
                d.push_back(num);
                graph1[num] = graph1[g] + 1;
            }
        }
        d.pop_front();
    }
    if (used[b]) {
        cout << graph1[b] << endl;
    }
    else{
        cout << -1 << endl;
    } 
}