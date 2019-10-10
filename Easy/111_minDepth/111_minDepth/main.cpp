//
//  main.cpp
//  111_minDepth
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
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;
        if (root == NULL) {
            return depth;
        }
        que.push(root);
        que.push(NULL);
        TreeNode* node;
        while (!que.empty()) {
            node = que.front();
            que.pop();
            if (node == NULL) {
                depth++;
                que.push(NULL);
                continue;
            }
            if (!(node->left) && !(node->right)) {
                depth++;
                return depth;
            }
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        return depth;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 7;
    int array[LEN] = {0,2,4,1,3,-1,5};
    vector<int>vec(array, array + LEN);
    cout << s.minDepth(createTree(vec)) << endl;
    return 0;
}
