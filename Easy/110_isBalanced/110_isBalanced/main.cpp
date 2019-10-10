//
//  main.cpp
//  110_isBalanced
//
//  Created by Bella Yang on 2019/10/9.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
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
private:
    int treeLength(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = treeLength(root->left);
        int right = treeLength(root->right);
        if (abs(left-right) > 1 || left == -1 || right == -1) {
            return -1;
        }
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return treeLength(root) != -1;
    }
};
    
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 9;
    int array[LEN] = {3,9,20,NULL,NULL,15,7};
    //    int array[LEN] = {1,2,2,3,4,4,3};
    //    int array[LEN] = {1,2,2,NULL,3,NULL,3};
    //    int array[LEN] = {9,25,25,NULL,-95,-95,NULL,-100,NULL,NULL,-15};
    vector<int> vec(array, array + LEN);
    cout << s.isBalanced(createTree(vec));
    return 0;
}
