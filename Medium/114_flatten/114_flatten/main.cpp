//
//  main.cpp
//  114_flatten
//
//  Created by Bella Yang on 2019/10/11.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
TreeNode* createTree(vector<int>& vec){
    if (vec.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(vec[0]);
    TreeNode* parentNode = root;
    TreeNode* newNode;
    queue<TreeNode*> que;
    que.push(root);
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] == NULL) {
            if (i% 2 == 0) {
                que.pop();
                parentNode = que.front();
            }
            continue;
        }
        newNode = new TreeNode(vec[i]);
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
    void flatten(TreeNode* root) {
        if (!root || (!(root->left) && !(root->right))) {
            return;
        }
        stack<TreeNode*>subtree;
        if (root->right) {
        subtree.push(root->right);
        }
        if (root->left) {
            subtree.push(root->left);
        }
        TreeNode* node;
        TreeNode* p = root;
        while (!subtree.empty()) {
            node = subtree.top();
            subtree.pop();
            p->left = NULL;
            p->right = node;
            p = node;
            if (node->right) {
                subtree.push(node->right);
            }
            if (node->left) {
                subtree.push(node->left);
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 7;
    int array[LEN] = {1,2,5,3,4,NULL,6};
    vector<int> vec(array, array + LEN);
    Solution s;
    s.flatten(createTree(vec));
    return 0;
}
