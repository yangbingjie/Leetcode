//
//  main.cpp
//  225_MyStack
//
//  Created by Bella Yang on 2019/11/18.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    bool is_q1;
public:
    /** Initialize your data structure here. */
    MyStack() {
        this->is_q1 = false;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (this->is_q1) {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }else{
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        this->is_q1 = !this->is_q1;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top;
        if (this->is_q1) {
            top = q1.front();
            q1.pop();
        }else{
            top = q2.front();
            q2.pop();
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        if (this->is_q1) {
            return q1.front();
        }else{
            return q2.front();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (this->is_q1) {
            return q1.empty();
        }else{
            return q2.empty();
        }
    }
};
int main(int argc, const char * argv[]) {
    MyStack stack = MyStack();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << stack.top() << endl;   // returns 2
    cout << stack.pop() << endl;   // returns 2
    cout << stack.empty() << endl; // returns false
    return 0;
}
