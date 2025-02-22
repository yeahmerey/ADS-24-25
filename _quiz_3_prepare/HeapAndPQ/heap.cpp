#include <bits/stdc++.h>
using namespace std;

class MaxHeap{ 
    private : 
        vector <int> heap ; 
        void heapifyDown(int index){
            int left = 2 * index + 1 ; 
            int right = 2 * index + 2 ; 
            int largest = index; 
            if(left < heap.size() && heap[left] > heap[largest]){
                largest = left ; 
            }
            if(right < heap.size() && heap[right] > heap[largest]){
                largest = right ;
            }
            if(largest != index){
                swap(heap[index] , heap[largest]); 
                heapifyDown(largest); 
            }
        }
        void heapifyUp(int index){
            while(index > 0 && heap[(index - 1) / 2] < heap[index]){
                swap(heap[index] , heap[(index - 1) / 2]); 
                index = (index - 1) / 2; 
            } 
        }
}