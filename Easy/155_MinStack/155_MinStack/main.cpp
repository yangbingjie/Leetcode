//
//  main.cpp
//  155_MinStack
//
//  Created by Bella Yang on 2019/10/20.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> sta;
public:
    MinStack() {
        
    }
    
    void push(int x) {
        if (this->sta.empty()) {
            this->sta.push(x);
        }else{
            int tmp = this->sta.top();
            this->sta.pop();
            int last_min = this->sta.top();
            this->sta.push(tmp);
            this->sta.push(min(last_min, x));
        }
        this->sta.push(x);
    }
    
    void pop() {
        this->sta.pop();
        this->sta.pop();
    }
    
    int top() {
        return this->sta.top();
    }
    
    int getMin() {
        int tmp = this->sta.top();
        this->sta.pop();
        int last_min = this->sta.top();
        this->sta.push(tmp);
        return last_min;
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
