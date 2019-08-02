//
//  main.cpp
//  2_addTwoNumbers
//
//  Created by Bella Yang on 2019/8/1.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list = NULL;
        ListNode* end = NULL;
        int value;
        bool overflow = false;
        while (l1 != NULL || l2 != NULL || overflow) {
            if (l1 != NULL && l2 != NULL) {
                value = l1->val + l2->val + overflow;                
                l1 = l1->next;
                l2 = l2->next;
            }else if (l1 != NULL){
                value = l1->val + overflow;;
                l1 = l1->next;
            }else if (l2 != NULL){
                value = l2->val + overflow;;
                l2 = l2->next;
            }else{
                value = 1;
                overflow = false;
            }
            if (value > 9){
                value -= 10;
                overflow = true;
            }else{
                overflow = false;
            }
            ListNode* tmp = new ListNode(value);
            if(list == NULL){
                list = tmp;
                end = tmp;
            }else{
                end->next = tmp;
                end = tmp;
            }
        }
        return list;
    }

};


ListNode* buildTree(vector<int>vec){
    ListNode* list = NULL;
    for (int i = int(vec.size()) - 1; i >= 0; i--) {
        ListNode* tmp = new ListNode(vec[i]);
        tmp->next = list;
        list = tmp;
    }
    return list;
}

int main(int argc, const char * argv[]) {
    Solution s;
    const int len1 = 2;
    const int len2 = 1;
    int array1[len1] = {9, 8};
    int array2[len2] = {1};
    vector<int> vec1(array1, array1 + len1);
    vector<int> vec2(array2, array2 + len2);
    ListNode* l1 = buildTree(vec1);
    ListNode* l2 = buildTree(vec2);
    
    ListNode* l= s.addTwoNumbers(l1, l2);
    
    while (l != NULL) {
        cout << l->val;
        l = l->next;
    }
    
    return 0;
}
