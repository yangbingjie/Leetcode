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
        for (int i = 0, j = int(s.size() - 1); i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
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
