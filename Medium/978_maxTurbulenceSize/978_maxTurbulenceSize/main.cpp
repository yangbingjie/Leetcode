//
//  main.cpp
//  978_maxTurbulenceSize
//
//  Created by Bella Yang on 2021/2/8.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2) {
            return arr.size();
        }
        vector<vector<int>>dp(2, vector<int>(2, 1));
        int max_size = 1;
        int old_ind, new_ind;
        for (int i = 1; i < arr.size(); ++i) {
            old_ind = i % 2;
            new_ind = (i + 1) % 2;
            if (arr[i] < arr[i - 1]) {
                dp[new_ind][0] = dp[old_ind][1] + 1;
                dp[new_ind][1] = 1;
            }else if (arr[i] > arr[i - 1]){
                dp[new_ind][0] = 1;
                dp[new_ind][1] = dp[old_ind][0] + 1;
            }else{
                dp[new_ind][0] = 1;
                dp[new_ind][1] = 1;
            }
            max_size = max(max_size, max(dp[new_ind][0], dp[new_ind][1]));
        }
        return max_size;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>arr = {9,4,2,10,7,8,8,1,9};
    Solution s;
    cout << s.maxTurbulenceSize(arr) << endl;
    return 0;
}
