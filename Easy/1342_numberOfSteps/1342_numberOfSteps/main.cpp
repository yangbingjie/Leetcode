//
//  main.cpp
//  1342_numberOfSteps
//
//  Created by bella on 2020/8/28.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num){
            if((num & 1) == 0){
                num >>= 1;
            }else{
                num -= 1;
            }
            count++;
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numberOfSteps(14) << endl;
    return 0;
}
