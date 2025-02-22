#include <bits/stdc++.h>

using namespace std;

vector <int> vec(10001, -1);
vector <int> used(10001, 0);

void bfs(int g){
    queue <int> q;
    q.push(g);
    used[g] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(a * 2 <= 10001 && !used[a * 2]){
            q.push(a * 2);
            vec[a * 2] = a;
            used[a * 2] = used[a] + 1;
        }
        if(a - 1 > 0 && !used[a - 1]){
            q.push(a - 1);
            vec[a - 1] = a;
            used[a - 1] = used[a] + 1;  
        }
    }
}

int main(){
    int n;
    int a;
    int b;
    cin >> a >> b;

    bfs(a);

    cout << used[b] - 1 << endl;
    vector <int> out;
    while(vec[b] != -1){
        out.push_back(b);
        b = vec[b];
    }
    reverse(out.begin(), out.end());
    for(int i = 0; i < out.size(); i++) {
        cout << out[i] << ' ';
    }
   
    
}