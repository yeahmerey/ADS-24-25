#include <iostream>
#include <vector>

using namespace std;

struct MinHeap {
    vector <char> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }

    void insert(char value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    char extractMin() {
        if(heap.size() == 1) {
            char root = heap[0];
            heap.pop_back();
            return root;
        }
        char root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }
        if(r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
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
    int n; cin >> n;
    string s; cin >> s;

    MinHeap *vowels = new MinHeap();
    MinHeap *consonants = new MinHeap();
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels->insert(s[i]);
        } else {
            consonants->insert(s[i]);
        }
    }

    while(vowels->getSize() > 0) {
        cout << vowels->extractMin();
    }
    while(consonants->getSize() > 0) {
        cout << consonants->extractMin();
    }
    cout << "\n";

    return 0;
}