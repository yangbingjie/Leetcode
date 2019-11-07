//
//  main.cpp
//  202_isHappy
//
//  Created by Bella Yang on 2019/11/7.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {

        vector<int> s;
        int result = -1;
        int tail;
        int num;
        while (s.end() == find(s.begin(), s.end(), result) ) {
            if (result == -1) {
                result = n;
            }else{
                s.push_back(result);
            }
            num = result;
            result = 0;
            while (num != 0) {
                tail = num % 10;
                result += tail * tail;
                num -= tail;
                num /= 10;
            }
        }
        vector<int>:: iterator pos = find(s.begin(), s.end(), result);
        return find(pos, s.end(), 1) != s.end();
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isHappy(1) << endl;
    return 0;
}
