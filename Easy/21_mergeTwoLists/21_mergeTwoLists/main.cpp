//
//  main.cpp
//  21_mergeTwoLists
//
//  Created by Bella Yang on 2019/8/30.
//  Copyright © 2019 Bella Yang. All rights reserved.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*head = NULL;
        ListNode*p1 = l1;
        ListNode*p2 = l2;
        if (p1 == NULL) {
            return l2;
        }
        if (p2 == NULL) {
            return l1;
        }
        if (p1->val >= p2->val) {
            head = p2;
            p2 = p2->next;
        }else{
            head = p1;
            p1 = p1->next;
        }
        
        ListNode*end = head;
        
        while (p1 != NULL && p2 != NULL) {
            if (p1 -> val >= p2 -> val) {
                end -> next = p2;
                end = p2;
                p2 = p2 -> next;
            }else{
                end -> next = p1;
                end = p1;
                p1 = p1->next;
            }
        }
        if (p1) {
            end -> next = p1;
        }
        if (p2) {
            end -> next = p2;
        }
        return head;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 2;
    const int LEN2 = 0;
    int array1[LEN1] = {1, 2};
    int array2[LEN2] = {};
    vector<int>vec1(array1, array1 + LEN1);
    vector<int>vec2(array2, array2 + LEN2);
    
    ListNode*l1 = create_list(vec1);
    ListNode*l2 = create_list(vec2);
    s.mergeTwoLists(l1, l2);
    return 0;
}
