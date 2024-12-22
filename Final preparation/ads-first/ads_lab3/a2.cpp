#include <bits/stdc++.h>
using namespace std;

typedef pair<int , pair<int,int>> pipii ;
typedef long long ll ;

pipii a[1000][1000] ;
int n , m  ;

void bin_search(int x ,int mx ,int mn){
    if(x < mn || x > mx){
        cout << "-1" << endl ;
    }
    int l = 1 ;
    int r = n * m - 1 ;
    int row , col ;
    while(l <= r){
        int mid = (l + r) / 2 ;
        row = mid / n ;
        col = mid % n ;
        if(x == a[row][col].first){
            cout <<  a[row][col].second.first  << " " << a[row][col].second.second << endl;
            break;
        }
        else if(x <  a[row][col].first){
            if(l +1 == r){
                cout <<  a[row][col].second.first  << " " << a[row][col].second.second + 1 << endl;
                break;
            }
            r = mid-1 ;

        }
        else{
            if(l +1 == r){
                cout <<  a[row][col].second.first  << " " << a[row][col].second.second + 1 << endl;
                break;
            }
            l = mid +1 ;
        }
    }
}


int main(){
    int inp ;
    scanf("%d" , &inp); int br[inp] ;
    for(int k = 0 ; k < inp ; k++){
        scanf("%d", &br[k]);
    }
    int mxmx , mnmn ;
    scanf("%d" "%d" , &n , &m) ;
    for(int i = 0  ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            scanf("%d" , &a[i][j].first);
            a[i][j].second.first = i ;
            a[i][j].second.second = j ;
        }
    }
    //sort
    vector <pipii> temp ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            temp.push_back(a[i][j]);
        }
    }
    sort(temp.begin() , temp.end());
    mxmx = temp[temp.size()].first ;
    mnmn = temp[0].first ;
    int k = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            a[i][j].first = temp[k].first ;
            a[i][j].second = temp[k].second ;
            k++;
        }
    }
    for(int k = 0 ; k < inp ; k++) {
        bin_search(br[k], mxmx , mnmn);
    }
}