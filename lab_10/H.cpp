#include <bits/stdc++.h>
using namespace std;
 
void DFS(vector<vector<int>> &M, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i > (n - 1) || j > (m - 1) || M[i][j] != 1)
    {
        return;
    }
 
    if (M[i][j] == 1)
    {
        M[i][j] = 0;
        DFS(M, i + 1, j, n, m);     
        DFS(M, i - 1, j, n, m);     
        DFS(M, i, j + 1, n, m);     
        DFS(M, i, j - 1, n, m);     
        DFS(M, i + 1, j + 1, n, m); 
        DFS(M, i - 1, j - 1, n, m); 
        DFS(M, i + 1, j - 1, n, m); 
        DFS(M, i - 1, j + 1, n, m); 
    }
}
 
int islands(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                M[i][j] = 0;
                count++;
                DFS(M, i + 1, j, n, m);     
                DFS(M, i - 1, j, n, m);     
                DFS(M, i, j + 1, n, m);     
                DFS(M, i, j - 1, n, m);     
                DFS(M, i + 1, j + 1, n, m); 
                DFS(M, i - 1, j - 1, n, m); 
                DFS(M, i + 1, j - 1, n, m); 
                DFS(M, i - 1, j + 1, n, m); 
            }
        }
    }
    return count;
}
 
int main()
{
    int t, d;
    cin >> t >> d;
    vector<vector<int>> M;
    string k;
    for (int i = 0; i < t; i++){
        vector<int> v;
        cin >> k;
        for(int j = 0; j < d; j++){
            v.push_back(k[j] - 48);
        }
        M.push_back(v);
    }
    for (int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[0].size(); j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
   
    cout << islands(M);
    return 0;
}