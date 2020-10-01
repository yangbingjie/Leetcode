//
//  main.cpp
//  LCP19_minimumOperations
//
//  Created by Bella Yang on 2020/10/1.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumOperations(string leaves) {
        vector<vector<int>>dp(leaves.size(), vector<int>(3));
        dp[0][0] = (leaves[0] != 'r');
        dp[0][1] = INT_MAX;
        dp[0][2] = INT_MAX;
        dp[1][2] = INT_MAX;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + (leaves[i] != 'r');
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (leaves[i] != 'y');
            if (i >= 2) {
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (leaves[i] != 'r');
            }
        }
        return dp[leaves.size() - 1][2];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.minimumOperations("rrryyyrryyyrr") << endl;
    return 0;
}
