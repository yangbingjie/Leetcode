//
//  main.cpp
//  100_isSameTree
//
//  Created by Bella Yang on 2019/9/29.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> tree1;
        stack<TreeNode*> tree2;
        tree1.push(p);
        tree2.push(q);
        while (!tree1.empty() && !tree2.empty()) {
            p = tree1.top();
            q = tree2.top();
            tree1.pop();
            tree2.pop();
            if ((!p && q) || (p && !q) ) {
//                cout<<'a';
                return false;
            }
            if (!p && !q) {
                continue;
            }
            if (p->val != q->val) {
//                cout<<'b';
                return false;
            }
            
            
            if (p->right && q->right&& p->right->val && q->right->val) {
                tree1.push(p->right);
                tree2.push(q->right);
            }else if ((!(p->right) && q->right) || (p->right && !(q->right))) {
//                cout<<'c';
                return false;
            }
            
            if (p->left && q->left && p->left->val && q->left->val) {
                tree1.push(p->left);
                tree2.push(q->left);
            }else if ((!(p->left) && q->left) || (p->left && !(q->left))) {
//                cout<<'d';
                return false;
            }
            
        }
        if (tree1.empty() && tree2.empty()) {
            return true;
        }else{
            return false;
        }
    }
};

TreeNode* add_node(TreeNode*root, vector<int>& vec, int index){
    if (index >= vec.size() || vec[index] == NULL) {
        return NULL;
    }
    root = new TreeNode(vec[index]);
    root->left = add_node(root, vec, 2 * index + 1);
    root->right = add_node(root, vec, 2 * index + 2);
    return root;
}
TreeNode* create_tree(vector<int>&vec){
    if (vec.size() == 0) {
        return NULL;
    }
    TreeNode* head = NULL;
    head = add_node(head, vec, 0);
    return head;
}


int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 3;
    const int LEN2 = 3;
    int array1[LEN1] = {1, NULL, 1};
    int array2[LEN2] = {1, NULL, 1};
    vector<int>vec1(array1, array1 + LEN1);
    vector<int>vec2(array2, array2 + LEN2);
    
    TreeNode*l1 = create_tree(vec1);
    TreeNode*l2 = create_tree(vec2);
    cout << s.isSameTree(l1, l2) << endl;

    return 0;
}
