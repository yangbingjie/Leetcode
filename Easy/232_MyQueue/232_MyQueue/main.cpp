//
//  main.cpp
//  232_MyQueue
//
//  Created by Bella Yang on 2019/11/18.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->s1.empty();
    }
};

int main(int argc, const char * argv[]) {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;
    return 0;
}
