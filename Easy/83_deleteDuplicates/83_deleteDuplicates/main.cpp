//
//  main.cpp
//  83_deleteDuplicates
//
//  Created by Bella Yang on 2019/9/15.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 != NULL) {
            if(p1 -> val == p2->val){
                p1->next = p2->next;
                delete p2;
                p2 = p1->next;
            }else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int array[LEN] = {1,1,2,3,3};
    vector<int>vec(array, array+LEN);
    ListNode* head = create_list(vec);
    s.deleteDuplicates(head);
    return 0;
}
