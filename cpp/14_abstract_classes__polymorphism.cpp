#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

/*
Developer:      Ruslan Arifullin
Date:           JUN 04 2018
                
DIFFICULTY:     HARD
    
PROBLEM:        You are given a main function which reads the enumeration values for two different
                types as input, then prints out the corresponding enumeration names. Write a class 
                template that can provide the names of the enumeration values for both types. If the
                enumeration value is not valid, then print unknown.

SAMPLE INPUT:   2
                1 0
                3 3

SAMPLE OUTPUT:  green apple
                unknown unknown
    
*/

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
private:
    int capacity = 0;
public:
    LRUCache(int cap) {capacity = cap;}

    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end())
            return it->second->value;

        return -1;
    }

    void set(int key, int value) {
        Node* node;

        if (mp.empty()) {
            node = new Node(key, value);
            tail = head = node;
            mp[key] = node;
            return;
        }

        auto it = mp.find(key);
        if (it == mp.end()) {
            // adding a new value
            node = new Node(head->prev, head, key, value);
            head->prev = node;
            head = node;
            mp[key] = node;

            if(mp.size() > capacity) {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = nullptr;
            }
        }
        else {
            it->second->value = value;
            if (head == it->second)
                return;

            it->second->prev->next = it->second->next;

            if (tail == it->second)
                tail = tail->prev;
            else
                it->second->next->prev = it->second->prev;

            it->second->next = head;
            it->second->prev = nullptr;
            head->prev = it->second;
            head = it->second;
        }

    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


