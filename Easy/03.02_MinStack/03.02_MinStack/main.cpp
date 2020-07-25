//
//  main.cpp
//  03.02_MinStack
//
//  Created by bella on 2020/7/25.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
struct Pair{
    int cur_num;
    int min_num;
    Pair(int c, int m):cur_num(c), min_num(m){}
};
class MinStack {
public:
    stack<Pair*> s;
    MinStack() {
        
    }
    
    void push(int x) {
        Pair* p;
        if (s.empty()) {
            p = new Pair(x, x);
            s.push(p);
        }else{
            p = new Pair(x, min(x, s.top()->min_num));
            s.push(p);
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top()->cur_num;
    }
    
    int getMin() {
        return s.top()->min_num;
    }
};

int main(int argc, const char * argv[]) {
    MinStack sta;
    sta.push(3);
    sta.pop();
    sta.push(-2);
    sta.push(0);
    sta.push(-3);
    cout << sta.getMin() << endl;   // 返回 -3.
    sta.pop();
    cout << sta.top() << endl;      // 返回 0.
    cout << sta.getMin() << endl;   // 返回 -2.
    return 0;
}
