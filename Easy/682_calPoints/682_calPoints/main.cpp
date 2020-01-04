//
//  main.cpp
//  682_calPoints
//
//  Created by Bella Yang on 2020/1/3.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> number;
        int points = 0;
        int tmp = 0;
        int t = 0;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "C") {
                points -= number.top();
                number.pop();
            }else if (ops[i] == "D"){
                tmp = number.top() * 2;
                points += tmp;
                number.push(tmp);
            }else if (ops[i] == "+"){
                tmp = number.top();
                number.pop();
                points += tmp + number.top();
                t = number.top();
                number.push(tmp);
                number.push(tmp + t);
            }else{
                tmp = stoi(ops[i]);
                number.push(tmp);
                points += tmp;
            }
        }
        return points;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 8;
    string arr[LEN] = {"5","-2","4","C","D","9","+","+"};
    vector<string> ops(arr, arr + LEN);
    cout << s.calPoints(ops) << endl;
    return 0;
}
