#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , s , to ; //Число вершин , рёбер , стартовая вершина и конечная вершина . 
    cin >> n >> m ; //enter number of vertices(n) and edges(m) : 
    vector<vector<int>> g(n) ; //граф в виде списка смежности
    for(int i = 0 ; i < m ; i ++){
        int u , v ; 
        cin >> u >> v ; 
        --u , --v ; //Переключаемся на 0-индексацию
        g[u].push_back(v) ; 
        g[v].push_back(u) ; //если граф неориентированный .
    }
    //enter start vertex(s) and end vertex(to) 
    cin >> s >> to ; 
    --s , --to ; //переключаемся на 0-индексацию 

    //BFS : 
    queue<int> q ; 
    vector<bool> used(n , false) ; //это массив, в котором мы храним информацию о том, были ли вершины уже посещены 
    vector<int> d(n, 0) , p(n , -1) ; //Расстояние и предшественники
    //Предшественники - мы будем сохранить инфо , с какой вершины мы пришли на каждую вершину , чтобы воостановить путь 
    q.push(s) ; // добавляем стартовую ввершину 
    used[s] = true; //помечаем первую вершину как посещенную

    p[s] = -1; //указываем что у начальной вершину нет предшественников. 

    while(!q.empty()){
        int v = q.front() ; 
        q.pop() ; 

        for(size_t i = 0 ; i < g[v].size() ; i ++){
            int to_vertex = g[v][i] ; 
            if(!used[to_vertex]){
                used[to_vertex] = true; 
                q.push(to_vertex) ; 
                d[to_vertex] = d[v] + 1 ; 
                p[to_vertex] = v; 
            }
        }
    }
    //Восстановление пути : 
    if(!used[to]){
        cout << "No path!" << endl ; 
    }else{
        vector<int> path ; 
        for(int v = to ; v != -1 ; v = p[v]){
            path.push_back(v) ; 
        }
        reverse(path.begin() , path.end()) ; //Переворачиваем путь
        cout << "Shortest path lenght : " << d[to] << endl ; 
        cout << "Path:" ;  
        for(size_t i = 0 ; i < path.size(); i ++){
            cout << path[i] + 1 << " "; 
        }
        cout << endl ; 
    }
    return 0 ; 
}