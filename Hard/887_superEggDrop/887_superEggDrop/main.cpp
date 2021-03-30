//
//  main.cpp
//  887_superEggDrop
//
//  Created by Bella Yang on 2021/3/29.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int superEggDrop(int k, int n) {
        if(n == 1){
            return 1;
        }
        vector<vector<int> >dp (n + 1, vector<int>(k + 1));
        for(int j = 1; j < k + 1; ++j){
            dp[1][j] = 1;
        }
        
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                dp[i][j] = 1 + dp[i - 1][j] + dp[i - 1][j - 1];
            }
            if(dp[i][k] >= n){
                return i;
            }
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.superEggDrop(3, 4) << endl;
    return 0;
}
