//
//  main.cpp
//  344_reverseString
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
    char array[LEN] = {'h', 'e', 'l', 'l', 'o'};
    vector<char> s(array, array + LEN);
    Solution so;
    so.reverseString(s);
    return 0;
}
