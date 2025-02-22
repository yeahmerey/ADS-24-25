    #include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

vector <int> vec[100001];
vector <int> used(1001);
int a, b;
bool flag;

void dfs(int g){
    used[g] = 1;

    for(int i : vec[g]){
    if(g == a && i == b) {
        continue;
    }
    else if(used[i] == 0) {
        dfs(i);
    }
    else if(used[i] == 1){
        flag = false;
        return;  
    }
  }

  used[g] = 2;
}



int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        for(int j : vec[i]){
            a = i; b = j;
            flag = true;
            fill(used.begin(), used.end(), 0);

        for(int i = 1; i <= n; i++){
            if(!used[i]){ 
                dfs(i);
            }
        }
        if(flag){
            return cout << "YES", 0;
        }
        }
    }
    cout << "NO" << endl;      
    return 0;
}