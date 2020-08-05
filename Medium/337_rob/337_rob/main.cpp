//
//  main.cpp
//  337_rob
//
//  Created by bella on 2020/8/5.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
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
    pair<int, int>* recurRob(TreeNode* root){
        if (!root) {
            return new pair<int, int>(0, 0);
        }
        pair<int, int>* left = recurRob(root->left);
        pair<int, int>* right = recurRob(root->right);
        int select = root->val + left->second + right->second;
        int no_select = max(left->first, left->second) + max(right->first, right->second);
        return new pair<int, int>(select, no_select);
    }
    int rob(TreeNode* root) {
        pair<int, int>*result = recurRob(root);
        return max(result->first, result->second);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 6;
    int array1[LEN1] = {4,1,NULL,2,NULL,3};
    vector<int>vec1(array1, array1 + LEN1);
    
    TreeNode*l1 = createTree(vec1);
    cout << s.rob(l1) << endl;
}
　
