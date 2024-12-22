#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> pipii ;

pipii a[100][100] ;
int n , m ;

void bin_search(int x , int mx , int mn){
    int l = 0 ;
    int r = n * m - 1  ;
    if(x < mn || x > mx){
        cout << "-1" ;
        return ;
    }
    else{
        while (l <= r) {
            int mid = (l + r) / 2;
            int row = mid / n;
            int col = mid % n;
            if (x == a[row][col].first) {
                cout << a[row][col].second.first << " " << a[row][col].second.second;
                return ;
            } else if (x < a[row][col].first) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
}
int main(){
    //input :
    int q ; cin >> q ; int b[q] ;
    for(int l = 0 ; l < q ; l++){
        cin >> b[l] ;
    }
    scanf("%d" "%d" , &n , &m) ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            scanf("%d" , &a[i][j].first) ;
            a[i][j].second.first = i ;
            a[i][j].second.second = j ;
        }
    }

    //sort ;
    vector <pipii> sorter ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            sorter.push_back(a[i][j]);
        }
    }
    sort(sorter.begin() , sorter.end()) ;
    int mx = sorter[sorter.size()-1].first ,  mn = sorter[0].first ;
    int k = 0 ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            a[i][j].first = sorter[k].first ;
            a[i][j].second = sorter[k].second ;
            k++ ;
        }
    }

    //print
    for(int l = 0 ; l < q ; l ++){
        bin_search(b[l],mx,mn) ;
        cout << "\n";
    }
    return 0 ;
}
