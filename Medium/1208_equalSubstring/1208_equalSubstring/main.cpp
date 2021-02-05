//
//  main.cpp
//  1208_equalSubstring
//
//  Created by Bella Yang on 2021/2/5.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>cost(s.size());
        for (int i = 0; i < cost.size(); ++i) {
            cost[i] = abs(s[i] - t[i]);
        }
        int result = 0;
        int fast = 0;
        int slow = 0;
        int curCost = 0;
        while (fast < cost.size()) {
            if (curCost + cost[fast] <= maxCost) {
                curCost += cost[fast];
                fast++;
                result = max(result, fast - slow);
            }else{
                curCost -= cost[slow];
                slow++;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.equalSubstring("abcd", "bcdf", 3) << endl;
    return 0;
}
