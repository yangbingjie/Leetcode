//
//  main.cpp
//  25_reverseKGroup
//
//  Created by Bella Yang on 2020/5/16.
//  Copyright © 2020 Bella Yang. All rights reserved.
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
    ListNode* reverseList(ListNode* head){
        if (!head || !head->next) {
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = NULL;
        ListNode* local_head = head;
        ListNode* local_end = head;
        ListNode* next_head = NULL;
        
        for (int i = 1; local_end != NULL && i < k; ++i) {
            local_end = local_end->next;
        }
        next_head = local_end->next;
        new_head = local_end;
        local_end->next = NULL;
        ListNode* p = reverseList(local_head);
        local_head->next = next_head;
        ListNode* pre_end = local_head;
        while (local_end != NULL) {
            local_head = next_head;
            local_end = next_head;
            for (int i = 1; local_end != NULL && i < k; ++i) {
                local_end = local_end->next;
            }
            if(local_end == NULL){
                break;
            }
            next_head = local_end->next;
            local_end->next = NULL;
            p = reverseList(local_head);
            local_head->next = next_head;
            pre_end->next = p;
            pre_end = local_head;
        }
        
        return new_head;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int array[LEN] = {1, 2, 3, 4, 5};
    vector<int>vec1(array, array + LEN);
    
    ListNode*head = create_list(vec1);
    s.reverseKGroup(head, 1);
    return 0;
}
