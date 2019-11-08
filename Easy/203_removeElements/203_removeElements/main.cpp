//
//  main.cpp
//  203_removeElements
//
//  Created by Bella Yang on 2019/11/8.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = head;
        while (node && node->val == val) {
            head = head->next;
            delete node;
            node = head;
        }
        ListNode* last_node = head;
        if (head) {
            node = head->next;
        }
        ListNode* p;
        while (node) {
            while (node && node->val == val) {
                p = node;
                node = node->next;
                delete p;
            }
            last_node->next = node;
            if (node) {
                last_node = node;
                node = node->next;
            }
        }
        return head;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 14;
    int array[LEN] = {1,2,2,2,2,2,1,1,1,2,2,1,3,4};
    vector<int> vec(array, array + LEN);
    Solution s;
    s.removeElements(create_list(vec), 2);
    return 0;
}
