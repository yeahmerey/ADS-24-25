#include <bits/stdc++.h>
using namespace std;
/*
Реализация на C++ выбирает опорный элемент,
разбивает массив на элементы, которые меньше
опорного элемента, и элементы, которые 
больше опорного элемента, а затем 
рекурсивно сортирует подмассивы.
*/
int partition(vector<int> &vec , int l , int r){
    int pivot = vec[r]; 
    int i = l - 1 ; 

    for(int j = l ; j <= r-1 ; j++){
        if(vec[j] <= pivot){
            i++; 
            swap(vec[i],vec[j]);
        }
    } 
    swap(vec[i+1] , vec[r]); 
    return (i+1); 
}
void quickSort(vector<int> &vec , int l , int r){
    if(l < r){
        int pivot = partition(vec , l , r); 
        quickSort(vec,l,pivot-1);
        quickSort(vec,pivot+1,r);  
    }
}
int main(){
    vector<int> vec = {10 , 7 , 8 , 9 , 2 , 6} ;
    int n = vec.size(); 
    quickSort(vec, 0 , n-1) ;
    for(auto i : vec){
        cout << i << " " ; 
    }
    return 0 ; 
}