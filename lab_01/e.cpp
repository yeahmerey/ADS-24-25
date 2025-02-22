#include <bits/stdc++.h>
using namespace std;

int main(){
    int temp , cntr = 0;
    deque <int> b ; deque <int> n ;
    for(int i = 0 ; i < 5;  i++){
        cin >> temp ; b.push_back(temp);
    }
    for(int i = 0 ; i < 5;  i++){
        cin >> temp ; n.push_back(temp);
    }
    for(int i = 0 ; i <= pow(10 , 6) ; i++){
        int bm , nm ; bm = b.front() ; nm = n.front() ;
        if(n.empty()){cout << "Boris " << cntr; break ;  }
        else if(b.empty()){cout << "Nursik " << cntr ; break ;}
        else if(bm > nm){
            if(bm == 9 and nm == 0){n.push_back(bm) ; n.push_back(nm) ; n.pop_front() ; b.pop_front() ; cntr++ ;}
            else{b.push_back(bm) ; b.push_back(nm) ;
                b.pop_front() ; n.pop_front() ; cntr++;}
        }
        else if(nm > bm){
            if(nm == 9 and bm == 0){b.push_back(bm) ; b.push_back(nm) ;b.pop_front() ; n.pop_front() ; cntr++;}
            else{n.push_back(bm) ; n.push_back(nm) ;
                n.pop_front() ; b.pop_front() ; cntr++ ;}
        }
        if(i == pow(10 , 6) - 1){cout << "blin nichya" ; }
    }
}