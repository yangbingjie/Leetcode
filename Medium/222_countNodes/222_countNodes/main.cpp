//
//  main.cpp
//  222_countNodes
//
//  Created by Bella Yang on 2020/11/24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int countLevel(TreeNode* root){
        int level = 0;
        while (root != 0) {
            level++;
            root = root->left;
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_level = countLevel(root->left);
        int right_level = countLevel(root->right);
        if (left_level == right_level) {
            return countNodes(root->right) + (1 << left_level);
        }else{
            return countNodes(root->left) + (1 << right_level);
        }
    }
};
int main(int argc, const char * argv[]) {
    vector<int>vec = {1,2,3,4,5,6};
    TreeNode* root = createTree(vec);
    Solution s;
    cout << s.countNodes(root) << endl;
    return 0;
}
