//
//  main.cpp
//  155_MinStack
//
//  Created by Bella Yang on 2019/10/20.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
struct MyListNode {
    int val;
    MyListNode* smaller;
    MyListNode* larger;
    MyListNode* next;
    MyListNode* last;
    MyListNode(int x):val(x), smaller(NULL),larger(NULL), next(NULL), last(NULL){}
};
class MinStack {
private:
    MyListNode* minNode;
    MyListNode* topNode;
public:
    MinStack() {
        this->minNode = NULL;
        this->topNode = NULL;
    }
    
    void push(int x) {
        MyListNode* node = new MyListNode(x);
        if (!this->minNode) {
            this->minNode = node;
            this->topNode = node;
            return;
        }
        this->topNode->next = node;
        node->last = this->topNode;
        this->topNode = node;
        
        MyListNode* pos = this->minNode;
        while (pos->larger && pos->val <= node->val) {
            pos = pos->larger;
        }
               
        if (pos->larger && pos->smaller) {
            MyListNode* tmp = pos->smaller;
            pos->smaller = node;
            node->smaller = tmp;
            node->larger = pos;
            tmp->larger = node;
        }else if(pos == this->minNode && pos->val >= node->val){
            this->minNode = node;
            pos->smaller = node;
            node->larger = pos;
        }else if (!pos->larger){
            pos->larger = node;
            node->smaller = pos;
        }else{
            cout << "ERROR" << endl;
        }
    }
    
    void pop() {
        MyListNode* node = this->topNode;
        this->topNode = node->last;
        if (node->last) {
            node->last->next = NULL;
        }
        if (node->larger && node->smaller) {
            node->larger->smaller = node->smaller;
            node->smaller->larger = node->larger;
        }else if (!node->larger&& node->smaller){
            node->smaller->larger = NULL;
        }else if(node->larger && !node->smaller){
            node->larger->smaller = NULL;
            this->minNode = node->larger;
        }else{
            this->minNode = NULL;
            this->topNode = NULL;
        }
        delete node;
    }
    
    int top() {
        return this->topNode->val;
    }
    
    int getMin() {
        return this->minNode->val;
    }
};


int main(int argc, const char * argv[]) {
    MinStack minStack = MinStack();
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);
    cout << minStack.top() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout<< minStack.getMin() << endl;
    minStack.pop();
    minStack.push(2147483647);
    cout << minStack.top() << endl;
    cout<< minStack.getMin() << endl;
    minStack.push(-2147483648);
    cout << minStack.top() << endl;
    cout<< minStack.getMin() << endl;
    minStack.pop();
    cout<< minStack.getMin() << endl;
    return 0;
}
