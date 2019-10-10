//
//  main.cpp
//  112_hasPathSum
//
//  Created by Bella Yang on 2019/10/10.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        int pathSum = 0;
        stack<TreeNode*> nodePath;
        stack<TreeNode*> subTree;
        subTree.push(root);
        TreeNode* node;
        while (!subTree.empty()) {
            node = subTree.top();
            nodePath.push(node);
            subTree.pop();
            pathSum += node->val;
            if (!(node->left) && !(node->right)) {
                if (pathSum == sum) {
                    return true;
                }else{
                    pathSum -= node->val;
                    nodePath.pop();
                    while (!subTree.empty() && !nodePath.empty() && nodePath.top()->right != subTree.top()) {
                        pathSum -= nodePath.top()->val;
                        nodePath.pop();
                    }
                    if (nodePath.empty() || subTree.empty()) {
                        return false;
                    }
                    continue;
                }
            }
            if (node->right) {
                subTree.push(node->right);
            }
            if (node->left) {
                subTree.push(node->left);
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 1;
    int array[LEN] = {1};
//    int array[LEN] = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1};
    //    int array[LEN] = {1,2,2,3,4,4,3};
    //    int array[LEN] = {1,2,2,NULL,3,NULL,3};
    //    int array[LEN] = {9,25,25,NULL,-95,-95,NULL,-100,NULL,NULL,-15};
    vector<int> vec(array, array + LEN);
    cout << s.hasPathSum(createTree(vec), 2) << endl;
    return 0;
}
