//
//  main.cpp
//  143_reorderList
//
//  Created by Bella Yang on 2020/10/20.
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
    ListNode* findMid(ListNode* head){
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        if (!head || !head->next) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
    void mergeList(ListNode* front, ListNode* back){
        ListNode * f_node = front;
        ListNode * b_node = back;
        ListNode * f_tmp;
        ListNode * b_tmp;
        while (f_node && f_node->next) {
            f_tmp = f_node->next;
            b_tmp = b_node->next;
            f_node->next = b_node;
            b_node->next = f_tmp;
            b_node = b_tmp;
            f_node = f_tmp;
        }
        if (b_node) {
            f_node->next = b_node;
        }
    }
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        ListNode* mid = findMid(head);
        ListNode* mid_next = mid->next;
        mid->next = NULL;
        ListNode* back = reverseList(mid_next);
        mergeList(head, back);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> vec = {1,2};
    ListNode * head = create_list(vec);
    Solution s;
    s.reorderList(head);
    return 0;
}
