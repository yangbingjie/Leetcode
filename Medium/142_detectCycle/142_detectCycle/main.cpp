//
//  main.cpp
//  142_detectCycle
//
//  Created by Bella Yang on 2020/10/10.
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
    ListNode *detectCycle(ListNode *head) {
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
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> vec = {3,2,0,-4};
    ListNode * head = create_list(vec);
    head->next->next->next->next = head->next;
    Solution s;
    s.detectCycle(head);
    return 0;
}
