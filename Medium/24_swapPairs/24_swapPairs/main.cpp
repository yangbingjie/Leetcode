//
//  main.cpp
//  24_swapPairs
//
//  Created by Bella Yang on 2019/9/1.
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



ListNode* createList(vector<int>vec){
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
    ListNode* recursionSwap(ListNode* left, ListNode* right){
        if (left && right) {
            if (right -> next && right->next->next) {
                left -> next = recursionSwap(right->next, right->next->next);
            }else{
                left -> next = right->next;
            }            
            right -> next = left;
        }
        return right;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head && head -> next) {
            head = recursionSwap(head, head->next);
        }
        return head;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int array[LEN] = {1, 2, 3, 4};
    vector<int> vec(array, array + LEN);
    ListNode* head = createList(vec);
    s.swapPairs(head);
    return 0;
}
