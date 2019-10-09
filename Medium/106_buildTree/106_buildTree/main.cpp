//
//  main.cpp
//  106_buildTree
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
    TreeNode* recurBuildTree(vector<int>& postorder,int postbegin, int postend,vector<int>& inorder, int inbegin, int inend) {
        if (postend <= postbegin) {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postend - 1]);
        if (postend - postbegin == 1) {
            return node;
        }
        int offset = 0;
        postend--;
        while (postorder[postend] != inorder[inbegin + offset]) {
            offset++;
        }
//                cout << offset <<"   " << postbegin << ',' << postbegin + offset<< "  " << inbegin <<',' << inbegin + offset << endl;
        node->left = recurBuildTree(postorder, postbegin, postbegin + offset, inorder, inbegin, inbegin + offset);
//                cout << offset <<"   " << postbegin + offset << ',' << postend - 1 << "  " << inbegin + offset + 1 <<',' << inend << endl;
        node->right = recurBuildTree(postorder, postbegin + offset, postend, inorder, inbegin + offset + 1, inend);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder) {
        return recurBuildTree(postorder, 0, int(postorder.size()), inorder, 0, int(inorder.size()));;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 1;
    int array1[LEN] = {1};
    int array2[LEN] = {1};
    
//    int array1[LEN] = {1,9,15,7,20,3};
//    int array2[LEN] = {1,9,3,15,20,7};
    vector<int>postorder(array1, array1 + LEN);
    vector<int>inorder(array2, array2 + LEN);
    s.buildTree(inorder, postorder);
    return 0;
}
