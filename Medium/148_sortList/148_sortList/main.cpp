//
//  main.cpp
//  148_sortList
//
//  Created by Bella Yang on 2020/11/21.
//

#include <iostream>
#include <vector>
using namespace std;
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
    ListNode* recurSort(ListNode* head, ListNode* tail){
        if (!head) {
            return head;
        }
        if (head->next == tail) {
            head->next = NULL;
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
            
        }
        ListNode* l1 = recurSort(head, slow);
        ListNode* l2 = recurSort(slow, tail);
        ListNode* sorted = merge(l1, l2);
        return sorted;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* new_head = new ListNode(0);
        ListNode* node = new_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            }else{
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            node->next = l1;
        }else if(l2){
            node->next = l2;
        }
        return new_head->next;
    }
    ListNode* sortList(ListNode* head) {
        return recurSort(head, NULL);
    }
};
int main(int argc, const char * argv[]) {
    vector<int>vec = {4,2,1,3};
    ListNode * head = create_list(vec);
    Solution s;
    s.sortList(head);
    return 0;
}
