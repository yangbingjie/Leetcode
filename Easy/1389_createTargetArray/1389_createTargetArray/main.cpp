//
//  main.cpp
//  1389_createTargetArray
//
//  Created by bella on 2020/7/30.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int v, Node*n=NULL):val(v),next(n){}
};
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        Node* head = new Node(nums[0]);
        Node* fast;
        Node* slow;
        Node* new_node;
        for (int i = 1; i < nums.size(); ++i) {
            if (index[i] == 0) {
                new_node = new Node(nums[i], head);
                head = new_node;
                continue;
            }
            fast = head->next;
            slow = head;
            for (int j = 1; j < index[i]; ++j) {
                fast = fast->next;
                slow = slow->next;
            }
            new_node = new Node(nums[i], fast);
            slow->next = new_node;
        }
        vector<int>result(nums.size());
        for (int i = 0; i < result.size(); ++i) {
            result[i] = head->val;
            head = head->next;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
    int arr1[LEN] = {1,2,3,4,0};
    int arr2[LEN] = {0,1,2,3,0};
    vector<int>nums(arr1, arr1 + LEN);
    vector<int>index(arr2, arr2 + LEN);
    Solution s;
    s.createTargetArray(nums, index);
    return 0;
}
