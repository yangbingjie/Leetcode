//
//  main.cpp
//  95_generateTrees
//
//  Created by Bella Yang on 2020/1/7.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<TreeNode*> recurGenerateTrees(int a, int b) {
        vector<TreeNode*> tree;
        if (a > b) {
            tree.push_back(NULL);
            return tree;
        }
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        TreeNode* node = NULL;
        for(int k = a; k <= b; ++k){
            left = recurGenerateTrees(a, k - 1);
            right = recurGenerateTrees(k + 1, b);
            for (int i = 0 ; i < left.size(); ++i) {
                for (int j = 0; j < right.size(); ++j) {
                    node = new TreeNode(k);
                    node->left = left[i];
                    node->right = right[j];
                    tree.push_back(node);
                }
            }
            
        }
        return tree;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return recurGenerateTrees(1, n);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<TreeNode*> v = s.generateTrees(3);
    return 0;
}
