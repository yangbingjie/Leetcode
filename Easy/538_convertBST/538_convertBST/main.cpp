//
//  main.cpp
//  538_convertBST
//
//  Created by Bella Yang on 2019/10/27.
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
private:
    int sum;
public:
    void reverseConvertBST(TreeNode* root){
        if (!root) {
            return;
        }
        reverseConvertBST(root->right);
        sum += root->val;
        root->val = sum;
        reverseConvertBST(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        this->sum = 0;
        reverseConvertBST(root);
        return root;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 7;
    int array[LEN] = {5,2,13, 1, 3, 7, 16};
    vector<int> nums(array, array + LEN);
    TreeNode*root = s.convertBST(createTree(nums));
    
    return 0;
}
