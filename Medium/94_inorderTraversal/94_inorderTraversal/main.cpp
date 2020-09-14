//
//  main.cpp
//  94_inorderTraversal
//
//  Created by bella on 2020/9/14.
//  Copyright © 2020 bella. All rights reserved.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*>sta;
        TreeNode*node = root;
        while (node) {
            sta.push(node);
            node = node->left;
        }
        while (!sta.empty()) {
            node = sta.top();
            sta.pop();
            result.push_back(node->val);
            node = node->right;
            while (node) {
                sta.push(node);
                node = node->left;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>vec = {1,2,3, 4,5,NULL, 7};
    TreeNode*root = createTree(vec);
    s.inorderTraversal(root);
    return 0;
}
