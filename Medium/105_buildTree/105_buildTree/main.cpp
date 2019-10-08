//
//  main.cpp
//  105_buildTree
//
//  Created by Bella Yang on 2019/10/8.
//  Copyright © 2019 Bella Yang. All rights reserved.
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
private:
    TreeNode* recurBuildTree(vector<int>& preorder,int prebegin, int preend,vector<int>& inorder, int inbegin, int inend) {
        if (preend <= prebegin) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prebegin]);
        if (preend - prebegin == 1) {
            return node;
        }
        int offset = 0;
        while (preorder[prebegin] != inorder[inbegin + offset]) {
            offset++;
        }
//        cout << offset <<"   " << prebegin + 1 << ',' << prebegin + offset + 1 << "  " << inbegin <<',' << inbegin + offset << endl;
        node->left = recurBuildTree(preorder, prebegin + 1, prebegin + offset + 1, inorder, inbegin, inbegin + offset);
//        cout << offset <<"   " << prebegin + offset + 1 << ',' << preend << "  " << inbegin + offset + 1 <<',' << inend << endl;
        node->right = recurBuildTree(preorder, prebegin + offset + 1, preend, inorder, inbegin + offset + 1, inend);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return NULL;
        }
        TreeNode*root = recurBuildTree(preorder, 0, int(preorder.size()), inorder, 0, int(inorder.size()));
        return root;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 1;
    int array1[LEN] = {1};
    int array2[LEN] = {1};

//    int array1[LEN] = {3,9,1,20,15,7};
//    int array2[LEN] = {1,9,3,15,20,7};
    vector<int>preorder(array1, array1 + LEN);
    vector<int>inorder(array2, array2 + LEN);
    s.buildTree(preorder, inorder);
    return 0;
}
