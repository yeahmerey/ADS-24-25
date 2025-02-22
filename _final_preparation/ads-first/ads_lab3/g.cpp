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
    int t = 6 ;
    int a; cin >> a; 
    printf("%02d",a );

}