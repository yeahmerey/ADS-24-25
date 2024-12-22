#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 ; //макс. кол:во вершин
vector<int> graph[MAXN] ; //список смежности
bool was[MAXN] ; //массив посещённых вершин

void dfs(int v){
    was[v] = true; //помещаем текущую вершину как посещенный
    cout << v << " " ; //Обработка текущую вершину (например , вывод)
    for(int u : graph[v]){
        if(!was[u]){
            dfs(u) ; 
        }
    }
}
int main(){
    int n , m ; cin >> n >> m ; //кол:во вершин и рёбер
    for(int i = 0 ; i < m ; i ++){
        int v , u ; 
        cin >> v >> u ; //Читаем ребро(v , u)
        graph[v].push_back(u) ; 
        graph[u].push_back(v) ; 
    }

    fill(was , was+n , false) ; 
    cout << "DFS traversal : " ; 
    dfs(0) ; //Запуск DFS с вершины 0 
    return 0 ; 
}