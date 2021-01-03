//
//  main.cpp
//  86_partition
//
//  Created by Bella Yang on 2021/1/3.
//

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* create_list(vector<int>vec){
    if (vec.size() == 0) {
        return NULL;
    }
    ListNode* head = new ListNode(vec[0]);
    ListNode* end = head;
    for (int i = 1; i < vec.size(); ++i) {
        ListNode* temp = new ListNode(vec[i]);
        end->next = temp;
        end = temp;
    }
    return head;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = NULL;
        ListNode* left_node = NULL;
        ListNode* right = NULL;
        ListNode* right_node = NULL;
        ListNode* node = head;
        while (node) {
            if (node->val < x) {
                if (!left) {
                    left = node;
                    left_node = node;
                    node = node->next;
                }else{
                    left_node->next = node;
                    node = node->next;
                    left_node = left_node->next;
                }
                left_node->next = NULL;
            }else{
                if (!right) {
                    right = node;
                    right_node = node;
                    node = node->next;
                }else{
                    right_node->next = node;
                    node = node->next;
                    right_node = right_node->next;
                }
                right_node->next = NULL;
            }
        }
        left_node->next = right;
        return left;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> vec = {1};
    ListNode* head = create_list(vec);
    s.partition(head, 0);
    return 0;
}
