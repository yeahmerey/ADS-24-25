#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <int> vec[10001];
vector <int> used(10001, 10001);

void bfs(int g){
    queue <int> q;
    q.push(g);
    used[g] = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i = 0; i < vec[a].size(); i++){
            if(used[a]+1 < used[vec[a][i]]){
                used[vec[a][i]] = used[a] + 1;
                q.push(vec[a][i]);    
      }
    }
  }
}

int main(){
    int n;
    int q;
    int m;
    int a;
    int b;
    cin >> n >> m >> q;

    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    while(q--){
        cin >> a >> b;
        if(a == 1){
            bfs(b);
        }
        else{
            cout << (used[b] == 10001 ? -1 : used[b]) << '\n';
        }
    }
}