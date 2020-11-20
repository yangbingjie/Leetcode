//
//  main.cpp
//  147_insertionSortList
//
//  Created by Bella Yang on 2020/11/20.
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* node;
        while (slow && fast) {
            node = head;
            while (node && node->next && node->next->val < fast->val) {
                node = node->next;
            }
            if (node == head && head->val > fast->val) {
                slow->next = fast->next;
                fast->next = head;
                head = fast;
            }else{
                if (node->next != fast) {
                    slow->next = fast->next;
                    ListNode * tmp = node->next;
                    node->next = fast;
                    fast->next = tmp;
                }else{
                    slow = slow->next;
                }
            }
            if (slow) {
                fast = slow->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> vec = {4,2,1,3};
//    vector<int> vec = {-1,5,3,4,0};
    ListNode * head = create_list(vec);
    Solution s;
    s.insertionSortList(head);
    return 0;
}
