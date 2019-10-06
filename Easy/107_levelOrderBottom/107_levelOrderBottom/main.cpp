//
//  main.cpp
//  107_levelOrderBottom
//
//  Created by Bella Yang on 2019/10/6.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        TreeNode* p = nullptr;
        vector<int> level;
        while (que.size() > 1) {
            level.clear();
            p = que.front();
            que.pop();
            while (p != NULL) {
                if (p->left) {
                    que.push(p->left);
                }
                if (p->right) {
                    que.push(p->right);
                }
                level.push_back(p->val);
                p = que.front();
                que.pop();
            }
            que.push(NULL);
            result.insert(result.begin(), level);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 7;
//    int array[LEN] = {1};
    int array[LEN] = {3,9,20,NULL,NULL,15,7};
//        int array[LEN] = {1,2,2,3,4,4,3};
    //    int array[LEN] = {1,2,2,NULL,3,NULL,3};
    //    int array[LEN] = {9,25,25,NULL,-95,-95,NULL,-100,NULL,NULL,-15};
    vector<int> vec(array, array + LEN);
    s.levelOrderBottom(createTree(vec));
    return 0;
}
