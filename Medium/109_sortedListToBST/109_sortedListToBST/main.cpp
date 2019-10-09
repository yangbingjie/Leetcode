//
//  main.cpp
//  109_sortedListToBST
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

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    TreeNode* recurSortedListToBST(ListNode* begin, ListNode* end) {
        if (begin == end) {
            return NULL;
        }
        if (begin->next == end) {
            return new TreeNode(begin->val);
        }
        ListNode* fast = begin;
        ListNode* slow = begin;
        while (fast && fast->next && fast->next->next && fast->next != end && fast->next->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = recurSortedListToBST(begin, slow);
        node->right = recurSortedListToBST(slow->next, end);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return recurSortedListToBST(head, NULL);
    }
};

ListNode* createLinkedList(vector<int>&nums){
    if (nums.empty()) {
        return NULL;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* p = head;
    for (int i = 1; i < nums.size(); ++i) {
        p -> next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

int main(int argc, const char*  argv[]) {
    Solution s;
    const int LEN = 7;
    int array[LEN] = {0,1,2,3,4,5,6};
    vector<int>nums(array, array + LEN);
    TreeNode* root = s.sortedListToBST(createLinkedList(nums));
    return 0;
}
