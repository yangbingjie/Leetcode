//
//  main.cpp
//  133_cloneGraph
//
//  Created by bella on 2020/8/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* recurClone(Node* old_node,Node* is_visited[]){
        if (!old_node) {
            return NULL;
        }
        Node* new_node = new Node(old_node->val);
        is_visited[old_node->val] = new_node;
        int val;
        vector<Node*>neighbors;
        for (int i = 0; i < old_node->neighbors.size(); ++i) {
            val = old_node->neighbors[i]->val;
            if (is_visited[val] != NULL) {
                neighbors.push_back(is_visited[val]);
            }else{
                Node* node = recurClone(old_node->neighbors[i], is_visited);
                neighbors.push_back(node);
            }
        }
        new_node->neighbors = neighbors;
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        Node* is_visited[101] = {NULL};
        Node* new_node = recurClone(node, is_visited);
        return new_node;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    vector<Node*>neighbor1;
    neighbor1.push_back(node2);
    neighbor1.push_back(node4);
    node1->neighbors= neighbor1;
    
    vector<Node*>neighbor2;
    neighbor2.push_back(node1);
    neighbor2.push_back(node3);
    node2->neighbors= neighbor2;
    
    vector<Node*>neighbor3;
    neighbor3.push_back(node2);
    neighbor3.push_back(node4);
    node3->neighbors= neighbor3;
    
    vector<Node*>neighbor4;
    neighbor4.push_back(node1);
    neighbor4.push_back(node3);
    node4->neighbors= neighbor4;
    s.cloneGraph(node1);
    return 0;
}
