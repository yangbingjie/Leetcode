//
//  main.cpp
//  926_minFlipsMonoIncr
//
//  Created by Bella Yang on 2020/10/8.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int last_zero = (S[0] != '0');
        int last_one = (S[0] != '1');
        int zero, one;
        for (int i = 1; i < S.size(); ++i) {
            zero = last_zero + (S[i] != '0');
            one = min(last_zero, last_one) + (S[i] != '1');
            last_one = one;
            last_zero = zero;
        }
        return min(zero, one);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.minFlipsMonoIncr("010110") << endl;
    return 0;
}
