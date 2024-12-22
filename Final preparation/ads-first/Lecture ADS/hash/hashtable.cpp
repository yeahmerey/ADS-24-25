#include <bits/stdc++.h>
using namespace std;

class node {
    private :
        string data ; 
        node * next ;
    public : 
        node(string data){
            this->data = data ; 
            next = nullptr; 
        }    
        string getData(){
            return data ; 
        }
        node * getNext(){
            return next ; 
        }
        void setData(string data){
            this->data = data ;
        }
        void setNext(node * next){
            this->next = next ; 
        }
}; 
class List{
    private :
        node * head ; 
    public : 
        List(){
            head = nullptr ; 
        }    
        void clear(node * node){
            if(node){
                if(node->getNext())
                    clear(node->getNext()); 
                delete node;    
            }
        }
        ~List(){
            clear(head); 
        }
        void insert(string s){
            node * newNode = new node(s); 
            if(head == nullptr){
                head = newNode ; 
            }
            else{
                node * cur = head; 
                while(cur->getNext()){
                    cur = cur->getNext();
                }
                cur->setNext(newNode); 
            }
        }
        void print(){
            node * cur = head ; 
            while(cur){
                cout << cur->getData() << "<=>"; 
                cur = cur->getNext(); 
            }
            cout << endl ; 
        }
        node * find(string s){
            if(head){
                node * cur = head ; 
                while(cur){
                    if(cur->getData() == s){
                        return cur ; 
                    }
                    cur = cur->getNext() ;
                }
            }
            return nullptr; 
        }
}; 

class HashTable{
    private : 
        List * content ;  
        int m ; 
    public :
        HashTable(int size){
            content = new List[size]; 
            m = size ; 
        }    
        ~HashTable(){
            delete[] content; 
        }
        int hash(string s){
            int sum = 0 ; 
            for(int i = 0 ; i < s.length() ; i++){
                sum += s.at(i) * pow(128 , i); 
            }
            return sum%m ; 
        }
        void insert(string s){
            content[hash(s)].insert(s); 
        }
        void print(){
            for(int i = 0 ; i < m ; i ++){
                content[i].print(); 
            }
        }
        node * find(string s){
            int probe = hash(s) ;
            return content[probe].find(s); 
        }
};

int main(){
    HashTable h(10); 
    h.insert("ha");
    h.insert("he");
    h.insert("ho");
    h.insert("hu");
    h.print();
    cout<<h.find("he")->getData();
    return 0;
}