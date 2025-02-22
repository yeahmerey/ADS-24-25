#include <bits/stdc++.h>
using namespace std;
int main(){
    char symbol ; int num ;
    deque <int> dq ;
    while(symbol != '!'){
        cin >> symbol ;
        if(symbol == '*') {
            if (dq.size() == 1 ) {
                cout << dq.front() + dq.front() << " " << endl ;
                dq.pop_front() ;
            } else if (dq.size() == 0) {
                cout << "error" << endl ;
            } else {
                cout << dq.front() + dq.back() << endl;
                dq.pop_front();
                dq.pop_back();
            }
        }
        else if(symbol == '+'){
            cin >> num ;
            dq.push_front(num) ;
        }
        else if(symbol == '-'){
            cin >> num ;
            dq.push_back(num) ;
        }
    }
}