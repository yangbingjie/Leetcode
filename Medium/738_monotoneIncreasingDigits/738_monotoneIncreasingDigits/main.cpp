//
//  main.cpp
//  738_monotoneIncreasingDigits
//
//  Created by Bella Yang on 2020/12/15.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string result = to_string(N);
        for (int i = result.size() - 2; i >= 0; --i) {
            if (result[i] > result[i + 1]) {
                result[i]--;
                for (int j = i + 1; j < result.size(); ++j) {
                    result[j] = '9';
                }
            }
        }
        return stoi(result);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.monotoneIncreasingDigits(332) << endl;
    return 0;
}
