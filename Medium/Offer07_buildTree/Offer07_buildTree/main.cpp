//
//  main.cpp
//  Offer07_buildTree
//
//  Created by Bella Yang on 2020/10/12.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
public:
    TreeNode * recurBuild(vector<int>&preorder, int p_start, int p_end,vector<int>& inorder, int i_start, int i_end){
        if (i_start > i_end || p_start > p_end) {
            return NULL;
        }
        TreeNode * node = new TreeNode(preorder[p_start]);
        int pos = 0;
        while (pos + i_start <= i_end) {
            if (inorder[pos + i_start] == preorder[p_start]) {
                break;
            }
            pos++;
        }
        node->left = recurBuild(preorder, p_start + 1, p_start + pos, inorder, i_start, i_start + pos - 1);
        node->right = recurBuild(preorder, p_start + pos + 1, p_end, inorder, i_start + pos + 1, i_end);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        return recurBuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    return 0;
}
