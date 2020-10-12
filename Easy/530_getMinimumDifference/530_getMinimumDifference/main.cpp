//
//  main.cpp
//  530_getMinimumDifference
//
//  Created by Bella Yang on 2020/10/12.
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
private:
    unsigned int diff;
    int last;
public:
    void dfs(TreeNode * node){
        if(!node){
            return;
        }
        if(node->left){
            dfs(node->left);
        }
        int new_diff = abs(double(node->val) - double(last));
        if(last != -1 && diff > new_diff){
            diff = new_diff;
        }
        last = node->val;
        if(node->right){
            dfs(node->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        last = -1;
        diff = -1;
        dfs(root);
        return diff;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>vec = {1564,1434,3048,1,NULL,NULL,3184};
    Solution s;
    cout << s.getMinimumDifference(createTree(vec)) << endl;
    return 0;
}
