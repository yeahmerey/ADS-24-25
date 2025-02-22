#include <bits/stdc++.h>
using namespace std; 

class MinHeap{
    
    public:
    vector<int> vec;
    
    int Parent(int i){ return (i-1)/2; }
    int Left(int i){ return i*2+1; }
    int Right(int i){ return i*2+2; }

    void insert(int value){
        vec.push_back(value);
        int i = vec.size()-1;

        while(i != 0 && vec[i] < vec[Parent(i)]){
            swap(vec[i],vec[Parent(i)]);
            i = Parent(i);
        }
    }

    void Heapify(int i){
        int smallest = i;
        int n = vec.size();
        if(Left(i) < n && vec[Left(i)] < vec[smallest])
            smallest = Left(i);
        if(Right(i) < n && vec[Right(i)] < vec[smallest])
            smallest = Right(i);

        if(i != smallest){
            swap(vec[smallest], vec[i]);
            Heapify(smallest);
        }
    }

    void _out(){
        int n = vec.size() - 1;
        for(int i = 0; i < n ; i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
};