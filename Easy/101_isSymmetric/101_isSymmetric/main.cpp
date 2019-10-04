//
//  main.cpp
//  101_isSymmetric
//
//  Created by Bella Yang on 2019/10/4.
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
    bool isSymmetric(TreeNode* root) {
        if (!root || (!(root->left) && !(root->right))) {
            return true;
        }
        if ((!(root->left) && (root->right)) || ((root->left) && !(root->right))) {
            return false;
        }
        stack<TreeNode*> left_tree;
        stack<TreeNode*> right_tree;
        left_tree.push(root->left);
        right_tree.push(root->right);
        TreeNode* left_node;
        TreeNode* right_node;
        while (!left_tree.empty() || !right_tree.empty()) {
            left_node = left_tree.top();
            left_tree.pop();
            right_node = right_tree.top();
            right_tree.pop();
            if ((left_node && !right_node) || (!left_node && right_node) || left_node->val != right_node->val) {
                return false;
            }
            if (left_node->right && right_node->left) {
                left_tree.push(left_node->right);
                right_tree.push(right_node->left);
            }else if ((left_node->right) || (right_node->left)){
                return false;
            }
            if (left_node->left && right_node->right) {
                left_tree.push(left_node->left);
                right_tree.push(right_node->right);
            }else if (left_node->left || right_node->right){
                return false;
            }
        }
        if (left_tree.empty() && right_tree.empty()) {
            return true;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array[LEN] = {1,2, 2};
//    int array[LEN] = {1,2,2,3,4,4,3};
//    int array[LEN] = {1,2,2,NULL,3,NULL,3};
//    int array[LEN] = {9,25,25,NULL,-95,-95,NULL,-100,NULL,NULL,-15};
    vector<int> vec(array, array + LEN);
    cout << s.isSymmetric(createTree(vec));
    return 0;
}
