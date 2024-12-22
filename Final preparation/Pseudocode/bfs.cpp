#include <bits/stdc++.h>
using namespace std;
int const maxn = 100 ;
int const n = 20 ;
vector<int> g[maxn] ; 
void bfs(int s){
    queue<int> q ; 
    q.push(s) ; 
    
    vector<int> d(n , -1) , p(n); 
    d[s] = 0 ; 
    while(!q.empty()){
        int v = q.front() ; 
        q.pop() ; 
        for(int u : g[v]){
            if(d[u] == -1){
                q.push(u) ; 
                d[u] = d[v] + 1 ; 
                p[u] = v ; 
            }
        }
    }
}