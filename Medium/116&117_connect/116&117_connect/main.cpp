//
//  main.cpp
//  116_connect
//
//  Created by Bella Yang on 2019/10/12.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

Node* createTree(vector<int>& vec){
    if (vec.empty()) {
        return NULL;
    }
    Node* root = new Node(vec[0], NULL, NULL, NULL);
    Node* parentNode = root;
    Node* newNode;
    queue<Node*> que;
    que.push(root);
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] == NULL) {
            if (i% 2 == 0) {
                que.pop();
                parentNode = que.front();
            }
            continue;
        }
        newNode = new Node(vec[i], NULL, NULL, NULL);
        if (i % 2 == 1) {
            parentNode->left = newNode;
            que.push(newNode);
        }else{
            parentNode->right = newNode;
            que.push(newNode);
            que.pop();
            parentNode = que.front();
        }
    }
    return root;
}

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || (!(root->left) && !(root->right))) {
            return root;
        }
        queue<Node*> que;
        que.push(root);
        que.push(NULL);
        Node* node;
        while (!que.empty()) {
            node = que.front();
            que.pop();
            if (node == NULL) {
                if (que.empty()) {
                    break;
                }else{
                    que.push(NULL);
                    continue;
                }
            }
            node->next = que.front();
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 7;
    int array[LEN] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vec(array, array + LEN);
    Solution s;
    s.connect(createTree(vec));
    return 0;
}
