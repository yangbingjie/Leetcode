//
//  main.cpp
//  968_minCameraCover
//
//  Created by bella on 2020/9/22.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
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
    enum status{No_Camera, Has_Camera, No_Need};
    int count;
public:
    status dfs(TreeNode* node){
        if (!node) {
            return No_Need;
        }
        status left = dfs(node->left);
        status right = dfs(node->right);
        if (left == No_Camera || right == No_Camera) {
            count++;
            return Has_Camera;
        }
        return left == Has_Camera || right == Has_Camera ? No_Need : No_Camera;
    }
    int minCameraCover(TreeNode* root) {
        if (!root) {
            return 0;
        }
        count = 0;
        if (dfs(root) == No_Camera) {
            count++;
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> v= {1,2,NULL,5,4};
    Solution s;
    TreeNode * root = createTree(v);
    cout << s.minCameraCover(root) << endl;
    return 0;
}
