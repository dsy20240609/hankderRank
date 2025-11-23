

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache {
    public:
        void set(int a ,in b) override {
            if(mp.find(a) != mp.end()) {
                mp[a]->value=b;
                if(mp[a] != head) { // overwrite exsit value
                    Node* cur=mp[a];
                    cur->pre->next=cur->next; //delete cur
                    tail->next=cur;
                    cur->next=head;
                    head=cur;
                } // if head, then keep the order as it is
            } else {
                if(mp.size() < cp)  {// the cache is not full
                Node* toAdd = new Node(a,b);
                toAdd->next=head;
                tail->next=toAdd;
                toAdd->prev=tail;
                head->prev=toAdd;
                head=toAdd;
                mp.insert(pair<int,Node*>(a,toAdd));
                } else { // replace the least recent used element which is the header point;
                Node* newtail= tail->prev;
                Node* toAdd=new Node(a,b);
                toAdd->next=head;
                newTail->next=toAdd;
                toAdd->prev=newTail;
                head->prev=toAdd;
                head=toAdd;
                int keyToDelete = tail->key;
                mp.erase(keyToDelete);
                delete tail;
                tall=newtail;
                }
            }
        }
        int get(int a) override {
            map<int,Node*>::iterator it = mp.find(a);
            if(it !=mp.end()) {
                return it->second->value; 
            } else {
                return -1;
            }

        }
 }
int main() {


//latest testing version
class LRUCache : public Cache {
    public:
        LRUCache(int capacity): 
        void set(int a ,int b) override {
            if(mp.find(a) != mp.end()) {
                mp[a]->value=b;
                if(mp[a] != head) { // overwrite exsit value
                    Node* cur=mp[a];
                    cur->prev->next=cur->next; //delete cur
                    tail->next=cur;
                    cur->next=head;
                    head=cur;
                } // if head, then keep the order as it is
            } else {
                if(mp.size() < cp)  {// the cache is not full
                    Node* toAdd = new Node(nullptr,nullptr,a,b);
                    toAdd->next=head;
                    tail->next=toAdd;
                    toAdd->prev=tail;
                    head->prev=toAdd;
                    head=toAdd;
                    mp.insert(pair<int,Node*>(a,toAdd));
                } else { // replace the least recent used element which is the header point;
                    Node* newtail= tail->prev;
                    Node* toAdd=new Node(nullptr,nullptr,a,b);
                    toAdd->next=head;
                    newtail->next=toAdd;
                    toAdd->prev=newtail;
                    head->prev=toAdd;
                    head=toAdd;
                    int keyToDelete = tail->key;
                    mp.erase(keyToDelete);
                    delete tail;
                    tail=newtail;
                }
            }
        }
        int get(int a) override {
            map<int,Node*>::iterator it = mp.find(a);
            if(it !=mp.end()) {
                return it->second->value; 
            } else {
                return -1;
            }

        }
 };

 // this is the correct working code
 class LRUCache : public Cache {
    public:
        LRUCache(int capacity):Cache() {
            cp=capacity;
            tail=nullptr;
            head=nullptr;
        };
        void set(int a ,int b) override {
            if(mp.find(a) != mp.end()) {
                mp[a]->value=b;
                if(mp[a] != head) { // overwrite exsit value
                    Node* cur=mp[a];
                    head->prev=cur;
                    cur->next=head;
                    tail->next=cur;
                    cur->prev=tail;
                    head=cur;
                } // if head, then keep the order as it is
            } else {
                if(mp.size() < cp)  {// the cache is not full
                    Node* toAdd = new Node(nullptr,nullptr,a,b);
                    if(head != nullptr) {
                        head->prev=toAdd;
                        toAdd->next=head;
                        tail->next=toAdd;
                        toAdd->prev=tail;
                        head=toAdd;
                    } else {
                        head=toAdd;
                        tail=toAdd;
                        head->next=tail;
                        head->prev=tail;
                    }
                    mp.insert(pair<int,Node*>(a,toAdd));
                } else { // replace the least recent used element which is the header point;
                    Node* toAdd=new Node(nullptr,nullptr,a,b);
                    tail->next=nullptr;
                    head->prev=nullptr;
                    Node* tailPrev=tail->prev;
                    tailPrev->next=toAdd;
                    toAdd->prev=tailPrev;
                    toAdd->next=head;
                    head->prev=toAdd;
                     
                    int keyToDelete = tail->key;
                    mp.erase(keyToDelete);
                    delete tail;
                    head=toAdd;
                    tail=toAdd->prev;
                }
            }
        }
        int get(int a) override {
            map<int,Node*>::iterator it = mp.find(a);
            if(it !=mp.end()) {
                return it->second->value; 
            } else {
                return -1;
            }

        }
 };