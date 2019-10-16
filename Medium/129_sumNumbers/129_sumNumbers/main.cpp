//
//  main.cpp
//  129_sumNumbers
//
//  Created by Bella Yang on 2019/10/16.
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
        if (vec[i] == -1) {
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
    int countLeaf(TreeNode* root, int value){
        if (!root) {
            return 0;
        }
        value *= 10;
        value += root->val;
        if (!root->left && !root->right) {
            return value;
        }
        return  countLeaf(root->left, value) + countLeaf(root->right, value);;
    }
public:
    int sumNumbers(TreeNode* root) {
        return countLeaf(root, 0);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int array[LEN] = {4,9,0,5,1};
    vector<int>vec(array, array + LEN);
    cout << s.sumNumbers(createTree(vec));
    return 0;
}
