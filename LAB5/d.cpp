#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

struct MinHeap {
    vector <int> heap;
    int sum;
    MinHeap(){
        sum = 0;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }

    void insert(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        sum+=value;
    }

    int deleteMin() {
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
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if(r < heap.size() && heap[r] < heap[smallest]) smallest = r;
        if(smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }   
    }

    int getSize() {
        return heap.size();
    }
};

int main() {
    MinHeap *heap = new MinHeap();
    int q, k; cin >> q >> k;
    int cnt  = 0;
    while(q--){
        string command; cin >> command;
        if(command == "insert"){
            ull n; cin >>n;
            cnt++;

            if(cnt > k && n > heap->getMin()){
                heap->sum -= heap->getMin();
                heap->deleteMin();
                heap->insert(n);
            }else if(cnt<= k){
                heap->insert(n);
            }
            
        }else{
            cout << heap->sum << endl;
        }

    }

}