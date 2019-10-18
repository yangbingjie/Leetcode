//
//  main.cpp
//  144_preorderTraversal
//
//  Created by Bella Yang on 2019/10/18.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        stack<TreeNode*> sta;
        sta.push(root);
        TreeNode* node;
        while (!sta.empty()) {
            node = sta.top();
            sta.pop();
            result.push_back(node->val);
            if (node->right) {
                sta.push(node->right);
            }
            if (node->left) {
                sta.push(node->left);
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int array[LEN] = {1,NULL,2,3};
    vector<int>vec(array, array + LEN);
    s.preorderTraversal(createTree(vec));
    return 0;
}
