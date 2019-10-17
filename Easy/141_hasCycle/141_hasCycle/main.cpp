//
//  main.cpp
//  141_hasCycle
//
//  Created by Bella Yang on 2019/10/17.
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
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && slow) {
            if (slow->next) {
                slow = slow->next;
            }else{
                break;
            }
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            }else{
                break;
            }
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int array[LEN] = {3, 2, 0, -4};
    ListNode* head =  new ListNode(array[0]);;
    ListNode * p = head;
    for (int i = 1; i < LEN; ++i) {
        p->next = new ListNode(array[i]);
        p = p->next;
    }
    p->next = head->next;
    cout << s.hasCycle(head) << endl;
    return 0;
}
