//
//  main.cpp
//  108_sortedArrayToBST
//
//  Created by Bella Yang on 2019/10/9.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    TreeNode* recurSortedArrayToBST(vector<int>& nums, int begin, int end) {
        if (end <= begin) {
            return NULL;
        }
        if (end - begin == 1) {
            return new TreeNode(nums[begin]);
        }
        int mid = (begin + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = recurSortedArrayToBST(nums, begin, mid);
        node->right = recurSortedArrayToBST(nums, mid + 1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurSortedArrayToBST(nums, 0, int(nums.size()));
    }
};
int main(int argc, const char*  argv[]) {
    Solution s;
    const int LEN = 5;
    int array[LEN] = {-10,-3,0,5,9};
    vector<int>nums(array, array + LEN);
    TreeNode* root = s.sortedArrayToBST(nums);
    return 0;
}
