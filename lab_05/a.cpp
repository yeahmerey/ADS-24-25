#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

struct MinHeap {
    vector <ull> heap;
    ull sum;
    MinHeap(){
        sum = 0;
    }
    ull parent(ull i) {
        return (i - 1) / 2;
    }

    void insert(ull value) {
        heap.push_back(value);
        ull i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        sum+=value;
    }

    ull extract() {
        if(heap.size() == 0) return -1;
        if(heap.size() == 1) {
            ull root = heap[0];
            // sum-=heap[heap.size() - 1];
            heap.pop_back();
            return root;
        }
        ull root = heap[0];
        heap[0] = heap[heap.size() - 1];
        // sum-=heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }
    ull getMin(){
        if(getSize() == 0) return -1;
        return heap[0];
    }


    void heapify(ull i) {
        ull l = 2 * i + 1;
        ull r = 2 * i + 2;
        ull greatest = i;
        if(l < heap.size() && heap[l] < heap[greatest]) greatest = l;
        if(r < heap.size() && heap[r] < heap[greatest]) greatest = r;
        if(greatest != i) {
            swap(heap[greatest], heap[i]);
            heapify(greatest);
        }   
    }

    ull getSize() {
        return heap.size();
    }
};

int main() {
    MinHeap *heap = new MinHeap();
    ull n; cin >> n;
    while(n--){
        ull x; cin >> x;
        heap->insert(x);
    }
    ull sum = 0;
    while(heap->getSize()>1){
        ull frst = heap->extract();
        ull second = heap->extract();
        ull diff = frst + second;
        heap->insert(diff);
        sum += diff;
    }
    cout << sum;
    



}