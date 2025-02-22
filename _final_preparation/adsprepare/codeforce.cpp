#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ; cin >> t; 
    while(t--){
        string a ; cin >> a ;
            string main = ""; 
            for(int i = 2 ;i < a.size() ; i++){
                main += a[i];  
            }
        char b , e ; 
        if(a[0] =='0' && a[1] == '0' ){
            cout << "12" ; 
            cout << main << " AM" << endl ; 
        }
        else if(a[0] == '1' && int(a[1] > 50 && a[1] < 57)){
            cout <<  "0" << int(a[1]) - 50 ;
            cout << main << " PM"  << endl ;    
        }
        else if(a[0] == '2' && a[1] > 47 && a[1] < 53){
            if(a[1] > 47 && a[1] < 50){
                 cout << "0" << int(a[1]) - 40 ;
                 cout << main << " PM" << endl ; 
            }
            else{
                cout << "1" << int(a[1]) - 48 ; 
                cout << main << " PM" << endl;
            }
        }
        else if(a[0] == '1' && a[1] == '2' && (a[3] > 47 || a[4] > 47 )){
            cout << a[0] << a[1] << main << " PM" << endl ; 
        }
        else{
            cout<<a[0]<<a[1]<<main<< " AM" << endl; 
        }
    }
}