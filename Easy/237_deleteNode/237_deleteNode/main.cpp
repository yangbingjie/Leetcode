//
//  main.cpp
//  237_deleteNode
//
//  Created by Bella Yang on 2019/11/22.
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
    void deleteNode(ListNode* node) {
        ListNode*p = node;
        while (p->next) {
            p->val = p->next->val;
            if (!p->next->next) {
                p->next = NULL;
                return;
            }
            p = p -> next;
        }
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
    int array[LEN] = {1,2,3,4,5};
    vector<int> vec(array, array + LEN);
    Solution s;
    ListNode*head=create_list(vec);
    s.deleteNode(head->next);
    return 0;
}
