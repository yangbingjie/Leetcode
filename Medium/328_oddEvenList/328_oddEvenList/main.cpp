//
//  main.cpp
//  328_oddEvenList
//
//  Created by Bella Yang on 2020/11/13.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* odd_node = head;
        ListNode* even = head->next;
        ListNode* even_node = even;
        ListNode* node = even;
        while (node->next) {
            if (node->next) {
                odd_node->next = node->next;
                odd_node = odd_node->next;
                node = node->next;
            }
            if (node->next) {
                even_node->next = node->next;
                even_node = even_node->next;
                node = node->next;
            }else{
                even_node->next = NULL;
            }
        }
        odd_node->next = even;
        return head;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> vec = {1,2,3,4,5,6};
    Solution s;
    ListNode* head = create_list(vec);
    s.oddEvenList(head);
    return 0;
}
