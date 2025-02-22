#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

struct MaxHeap {
    vector <int> heap;
    int sum;
    MaxHeap(){
        sum = 0;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }

    void insert(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        sum+=value;
    }

    int deleteMax() {
        if(heap.size() == 0) return -1;
        if(heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }
    int getMin(){
        if(getSize() == 0) return -1;
        return heap[0];
    }


    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int greatest = i;
        if(l < heap.size() && heap[l] > heap[greatest]) greatest = l;
        if(r < heap.size() && heap[r] > heap[greatest]) greatest = r;
        if(greatest != i) {
            swap(heap[greatest], heap[i]);
            heapify(greatest);
        }   
    }

    int getSize() {
        return heap.size();
    }
};

int main() {
    MaxHeap *heap = new MaxHeap();
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        heap->insert(v[i]);
    }
    ull sum = 0;
    while(k--){
        int root = heap->deleteMax();
        sum += root;
        heap -> insert(--root);
    }
        
        
    cout << sum;
    



}