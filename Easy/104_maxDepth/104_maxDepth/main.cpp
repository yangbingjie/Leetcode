//
//  main.cpp
//  104_maxDepth
//
//  Created by Bella Yang on 2019/10/5.
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
    int recurMaxDepth(TreeNode* subroot) {
        if (!subroot) {
            return 0;
        }

        int left = recurMaxDepth(subroot->left);
        int right = recurMaxDepth(subroot->right);
//        cout<< subroot->val << ',' << left<< ',' <<  right <<endl;
        return max(left, right) + 1;
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL) {
            return depth;
        }
        depth++;
        if (!root->left && !root->right) {
            return depth;
        }
        return recurMaxDepth(root);;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array[LEN] = {1,2, 4};
//    int array[LEN] = {3,9,20,NULL,NULL,15,7};
    //    int array[LEN] = {1,2,2,3,4,4,3};
    //    int array[LEN] = {1,2,2,NULL,3,NULL,3};
    //    int array[LEN] = {9,25,25,NULL,-95,-95,NULL,-100,NULL,NULL,-15};
    vector<int> vec(array, array + LEN);
    cout << s.maxDepth(createTree(vec)) << endl;
    return 0;
}
