#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
    node(int x) {
        val = x;
        next = NULL;
    }
};

struct stack {
   private:
    node *head;
    node *tail;
    int len;

   public:
    stack() {
        head = tail = NULL;
        len = 0;
    }

    void push(int x){
        node * n = new node(x) ; 
        if(tail == NULL){
            head = tail = n  ;
        }
        else{
            tail->next = n ; 
            tail = n ; 
        }
    }
    void pop(){
        if(tail == NULL){
            cout << "Stack is empty" ; 
            return ; 
        }
        else if(tail == head){
            delete head ; 
            head = tail = NULL ; 
        }
        else{
            node * cur = head ;  
            while(cur->next != tail){
                cur = cur->next ; 
            }
            delete tail ; 
            tail = cur ; 
            tail->next  = NULL ;
        }
    }

    void print() {
        node *cur = head;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }

    int size() {
        return len;
    }

    bool isEmpty() {
        return len == 0;
    }

    int peek() {
        if (tail == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return tail->val;
    }
};

int main() {
    stack s;
    int a[] = {1, 20, 10, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);

    for (int i = 0; i < n; ++i) {
        s.push(a[i]);
    }
    cout << "Stack elements after pushing: ";
    s.print();
    cout << endl;

    s.pop();
    cout << "Stack elements after popping: ";
    s.print();
    cout << endl;

    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
