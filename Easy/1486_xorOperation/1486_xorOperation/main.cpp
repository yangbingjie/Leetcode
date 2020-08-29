//
//  main.cpp
//  1486_xorOperation
//
//  Created by bella on 2020/8/28.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        int result = start;
        int i = 1;
        while(i < n){
            result ^= (start + (i << 1));
            i++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.xorOperation(5, 0) << endl;
    return 0;
}
