//
//  main.cpp
//  19_removeNthFromEnd
//
//  Created by Bella Yang on 2019/8/28.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        vector<ListNode*> pointers;
        while (p != NULL) {
            pointers.push_back(p);
            p = p -> next;
        }
        int target = int(pointers.size() - n);
        if (target == 0) {
            if (pointers.size() > 1) {
                head = pointers[target + 1];
            }else{
                head = NULL;
            }            
        }else{
            pointers[target - 1] -> next = pointers[target] -> next;
        }
        delete pointers[target];
        return head;
    }
};

ListNode* create_list(vector<int>vec){
    ListNode* head = new ListNode(vec[0]);
    ListNode* end = head;
    for (int i = 1; i < vec.size(); ++i) {
        ListNode* temp = new ListNode(vec[i]);
        end->next = temp;
        end = temp;
    }
    return head;
}

int main() {
    Solution s;
    const int LEN = 1;
    int array[LEN] = {1};
    vector<int> vec(array, array + LEN);
    ListNode* head = create_list(vec);
    s.removeNthFromEnd(head, 1);
    return 0;
}
