//
//  main.cpp
//  1573_numWays
//
//  Created by Bella Yang on 2020/10/7.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int numWays(string s) {
        int ones = int(count(s.begin(), s.end(), '1'));
        if (ones % 3 != 0) {
            return 0;
        }
        if (ones == 0) {
            return ((s.size() - 1) * (s.size() - 2) / 2) % (1000000007);
        }
        ones /= 3;
        
        int visited_one = 0;
        int i = 0;
        for (;visited_one < ones; ++i) {
            if (s[i] == '1') {
                visited_one++;
            }
        }
        int left = 0;
        while (s[i] != '1') {
            left++;
            i++;
        }
        
        visited_one = 0;
        i = int(s.size() - 1);
        for (;visited_one < ones; --i) {
            if (s[i] == '1') {
                visited_one++;
            }
        }
        int right = 0;
        while (s[i] != '1') {
            right++;
            i--;
        }
        return (long(left + 1) * long(right + 1)) % (1000000007);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numWays("000000000000000000000000000000") << endl;
    return 0;
}
