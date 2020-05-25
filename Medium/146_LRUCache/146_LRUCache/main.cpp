//
//  main.cpp
//  146_LRUCache
//
//  Created by Bella Yang on 2020/5/25.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int k, int v, Node* p = NULL, Node* n=NULL):key(k), value(v),pre(p),next(n){}
};

class LRUCache {
private:
    Node*tail;
    Node*head;
    unordered_map<int, Node*>hash_map;
    int max_count;
    int count;
public:
    LRUCache(int capacity) {
        count = 0;
        max_count = capacity;
        tail = NULL;
        head = NULL;
    }
    void update(Node* node){
        if (node == tail) {
            return;
        }
        Node* pre_node = node->pre;
        Node* next_node = node->next;
        if (node == head) {
            head = next_node;
        }
        if (pre_node) {
            pre_node->next = next_node;
        }
        if (next_node) {
            next_node->pre = pre_node;
        }
        tail->next = node;
        node->pre = tail;
        node->next = NULL;
        tail = node;
    }
    void remove_old(){
        Node*delete_head = head;
        head = head->next;
        if(head){
            head->pre = NULL;
        }else{
            tail = NULL;
        }
        hash_map.erase(delete_head->key);
        delete delete_head;
    }
    int get(int key) {
        unordered_map<int, Node*>::iterator iter = hash_map.find(key);
        if (iter != hash_map.end()) {
            update(iter->second);
            return iter->second->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        unordered_map<int, Node*>::iterator iter = hash_map.find(key);
        if (iter != hash_map.end()) {
            iter->second->value = value;
            update(iter->second);
        }else{
            if (count < max_count) {
                count++;
            }else{
                remove_old();
            }
            Node* node = new Node(key, value);
            hash_map.insert(pair<int, Node*>(key, node));
            if (!head) {
                head = node;
            }
            if (tail) {
                node->pre = tail;
                tail->next = node;
            }
            tail = node;
        }
    }
};


int main(int argc, const char * argv[]) {
    LRUCache* cache = new LRUCache( 2 /* 缓存容量 */ );

    cache->put(1, 1);
    cache->put(2, 2);
    cout<< cache->get(1)<<endl;       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cout<< cache->get(2)<<endl;       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cout<< cache->get(1)<<endl;       // 返回 -1 (未找到)
    cout<< cache->get(3)<<endl;       // 返回  3
    cout<< cache->get(4)<<endl;       // 返回  4

    return 0;
}
