//
//  main.cpp
//  637_averageOfLevels
//
//  Created by bella on 2020/9/12.
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
        if (vec[i] == 0) {
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        vector<double>result;
        if (root) {
            q.push(pair<int, TreeNode*>(0, root));
        }
        pair<int, TreeNode*> node;
        long sum = 0;
        int count = 0;
        int level = 0;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (level != node.first) {
                result.push_back(double(sum) / double(count));
                sum = 0;
                count = 0;
                level = node.first;
            }
            sum += node.second->val;
            count++;
            if (node.second->left) {
                q.push(pair<int, TreeNode*>(node.first + 1, node.second->left));
            }
            if (node.second->right) {
                q.push(pair<int, TreeNode*>(node.first + 1, node.second->right));
            }
            
        }
        result.push_back(double(sum) / double(count));
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>vec = {2147483647,2147483647,2147483647};
    TreeNode * root = createTree(vec);
    Solution s;
    s.averageOfLevels(root);
    return 0;
}
