//
//  main.cpp
//  99_recoverTree
//
//  Created by bella on 2020/8/8.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* node = root;
        TreeNode* pre = NULL;
        TreeNode* x = NULL;
        TreeNode* y = NULL;
        while (!s.empty() || node != NULL) {
            while (node != NULL) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if (pre != NULL && pre->val > node->val) {
                y = node;
                if (!x) {
                    x = pre;
                }else{
                    break;
                }
            }
            pre = node;
            node = node->right;
        }
        swap(x->val, y->val);
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int arr[LEN] = {3,1,4,NULL,NULL,2};
    vector<int>vec(arr, arr + LEN);
    TreeNode* root = createTree(vec);
    Solution s;
    s.recoverTree(root);
    return 0;
}
