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

    int extract() {
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
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        heap->insert(x);
    }
    while(heap->getSize()>1){
        int frst = heap->extract();
        int second = heap->extract();
        int diff = frst - second;
        heap->insert(diff);
    }
    cout << heap->extract();
    



}