#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> pipii ;
typedef long long ll ;
const int N = (int)1e5 + 5  ;
const int M = (int)1e5 + 5 ;
const int t = 1000 ; 
pipii a[t][t] ;
int n , m ;



void bin_search(int x){
    if(x < a[0][0].first || x > a[n][m].first) return ;
    int l = 0 , r = n * m - 1 , temp = -1 , temp2 = -1;
    while(l <= r){
        int mid = (l + r) / 2 ;
        int row = mid / n , col = mid % n;
        if(x == a[row][col].first){cout <<  row  <<  " " <<  col ; return ;  }
        if(x <= a[row][col].first){
            temp = row ;
            temp2 = col ;
            r = mid - 1 ;
        }
        else{
            l = mid + 1 ;
        }
        cout <<  a[temp][temp2].second.first  << " " <<  a[temp][temp2].second.second << endl   ;
    }
}


int main(){
    scanf("%d" "%d" , &n , &m) ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            scanf("%d", &a[i][j].first) ;
            a[i][j].second.first = i ;
            a[i][j].second.second = j ;
        }
    }
    int size = n * m ;
    int oneD[size] ;
    int ind = 0 ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            oneD[ind++] = a[i][j].first ;
        }
    }
    sort(oneD , oneD + size) ;
    for(int i = 0 ; i < n ; i ++){

}