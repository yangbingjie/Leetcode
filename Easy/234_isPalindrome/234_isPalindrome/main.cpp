//
//  main.cpp
//  234_isPalindrome
//
//  Created by Bella Yang on 2019/11/21.
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* last = NULL;
        ListNode* p;
        slow = slow->next;
        
        while (slow->next) {
            p = slow->next;
            slow->next = last;
            last = slow;
            slow = p;
        }
        slow->next = last;
        
        while (slow && head) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 7;
    int array[LEN] = {1, 2, 3, 4, 3, 2, 1};
    vector<int>nums(array, array + LEN);
    ListNode* head = create_list(nums);
    cout << s.isPalindrome(head) << endl;
    return 0;
}
