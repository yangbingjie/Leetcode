//
//  main.cpp
//  1513_numSub
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int numSub(string s) {
        int result = 0;
        for (int slow = 0, fast = 0; fast < s.size();) {
            while (slow < s.size() && s[slow] != '1') {
                slow++;
            }
            fast = slow;
            while (fast < s.size() && s[fast] != '0') {
                result = (result + ((fast % 1000000007) - (slow %  1000000007) + 1) % 1000000007) % 1000000007;
                fast++;
            }
            fast++;
            slow = fast;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numSub("0110111") << endl;
    return 0;
}
