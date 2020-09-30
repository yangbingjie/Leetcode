//
//  main.cpp
//  701_insertIntoBST
//
//  Created by Bella Yang on 2020/9/30.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* new_node = new TreeNode(val);
        if (!root) {
            root = new_node;
            return root;
        }
        TreeNode * node = root;
        while (node->left || node->right) {
            if (node->val > val) {
                if (node->left) {
                    node = node->left;
                }else{
                    break;
                }
            }else{
                if (node->right) {
                    node = node->right;
                }else{
                    break;
                }
            }
        }
        if (node->val > val) {
            node->left = new_node;
        }else{
            node->right = new_node;
        }
        return root;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>tree = {NULL};
    TreeNode * root = createTree(tree);
    Solution s;
    s.insertIntoBST(root, 5);
    return 0;
}
