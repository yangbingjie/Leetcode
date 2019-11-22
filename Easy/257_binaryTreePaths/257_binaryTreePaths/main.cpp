//
//  main.cpp
//  257_binaryTreePaths
//
//  Created by Bella Yang on 2019/11/22.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    void recurBinaryTreePaths(vector<string>& vec,TreeNode* node, string str) {
        if (!node) {
            return;
        }
        string s = str + "->" + to_string(node->val);
        if (!node->left && !node->right) {
            vec.push_back(s);
        }
        if (node->left) {
            recurBinaryTreePaths(vec, node->left, s);
        }
        if (node->right) {
            recurBinaryTreePaths(vec, node->right, s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) {
            return result;
        }
        if (!root->left && !root->right) {
            result.push_back(to_string(root->val));
            return result;
        }
        recurBinaryTreePaths(result, root->left, to_string(root->val));
        recurBinaryTreePaths(result, root->right, to_string(root->val));
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 1;
//    int array[LEN] = {1,2,3,NULL,5, 6, 7, NULL, NULL, 8, 9};
    int array[LEN] = {1};
    vector<int> vec(array, array + LEN);
    TreeNode* head = createTree(vec);
    s.binaryTreePaths(head);
    return 0;
}
