//
//  main.cpp
//  02.04_partition
//
//  Created by bella on 2020/7/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast) {
            if (fast->val < x) {
                slow->next = fast->next;
                fast->next = head;
                head = fast;
                fast = slow->next;
            }else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        return head;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 2;
    int array[LEN] = {5, 2};
//    int array[LEN] = {3,5,8,5,10,2,1};
    vector<int> vec(array, array + LEN);
    Solution s;
    s.partition(create_list(vec), 5);
    return 0;
}
