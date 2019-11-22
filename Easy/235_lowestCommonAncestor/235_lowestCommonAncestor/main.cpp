//
//  main.cpp
//  235_lowestCommonAncestor
//
//  Created by Bella Yang on 2019/11/22.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        int max_value = max(p->val, q->val);
        int min_value = min(p->val, q->val);
        while (node) {
            if (node->val <= max_value) {
                if (node->val >= min_value) {
                    return node;
                }else{
                    node = node->right;
                }
            }else{
                node = node->left;
            }
        }
        return node;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 11;
    int array[LEN] = {6,2,8,-2,4,7,9,NULL,NULL,3,5};
    //    int array[LEN] = {1,2,2,3,4,4,3};
    //    int array[LEN] = {1,2,2,NULL,3,NULL,3};
    //    int array[LEN] = {9,25,25,NULL,-95,-95,NULL,-100,NULL,NULL,-15};
    vector<int> vec(array, array + LEN);
    TreeNode*root = createTree(vec);
    s.lowestCommonAncestor(root, root->left, root->left->right);
    return 0;
}
