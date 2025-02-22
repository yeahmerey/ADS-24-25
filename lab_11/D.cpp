#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector <int> graph[10001];
struct Edge {
    long long src, dest, weight;
};
 
struct compare
{
    bool operator() (Edge const &a, Edge const &b) const {
        return a.weight > b.weight;
    }
};
 
class DisjointSet
{   
    unordered_map<int, int> parent;
 
public:
    void makeSet(int n)
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    int Find(int k)
    {
        if (parent[k] == k) {
            return k;
        }
 
        return Find(parent[k]);
    }

    void Union(int a, int b)
    {
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};
 

vector<Edge> runKruskalAlgorithm(vector<Edge> edges, int n)       
{
    vector<Edge> MST;
    DisjointSet ds;
    ds.makeSet(n);
    sort(edges.begin(), edges.end(), compare());
 
    while (MST.size() != n - 1)
    {
        Edge next_edge = edges.back();
        edges.pop_back();
 
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);

        if (x != y)
        {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}
 
int main()
{   
    int a;
    cin >> a;
    vector<Edge> edges;
    long long cnt = 0;
    for(long long i = 1; i <= a; i++){
        for(long long j = 1; j <= a; j++ ){
            long long x;
            cin >> x;
            if(i != j)
                cnt++;
                edges.push_back({i, j, x});
            
        }
    }
    vector<Edge> e = runKruskalAlgorithm(edges, cnt);
    // for(Edge&edge : edges){
    //     cout << "(" << edge.src << ", " << edge.dest << ", "
    //          << edge.weight << ")" << endl;
    // }
    long long sum = 0;
    long long count = 0;
    for (Edge &edge: e)
    {
        sum = sum + edge.weight;
        count++;
    }

    if(count > 1){
        cout << sum;
    }
    else{
        cout << 0;
    }


    return 0;
}