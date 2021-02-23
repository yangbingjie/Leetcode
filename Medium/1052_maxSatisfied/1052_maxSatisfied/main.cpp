//
//  main.cpp
//  1052_maxSatisfied
//
//  Created by Bella Yang on 2021/2/23.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        vector<int>prefix(customers.size() + 1);
        prefix[0] = 0;
        for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] = prefix[i - 1];
            if (grumpy[i - 1] == 0) {
                prefix[i] += customers[i - 1];
            }
        }
        int fast = 0;
        int satisfied = 0;
        while (fast < X) {
            satisfied += customers[fast];
            fast++;
        }
        int slow = 0;
        int result = satisfied;
        if (fast < prefix.size()) {
            result = prefix[slow] + prefix[prefix.size() - 1] - prefix[fast] + satisfied;
        }
        while (fast < customers.size()) {
            satisfied += customers[fast];
            satisfied -= customers[slow];
            slow++;
            fast++;
            result = max(result, prefix[slow] + prefix[prefix.size() - 1] - prefix[fast] + satisfied);
            
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy =    {0,1,0,1,0,1,0,1};
    Solution s;
    cout << s.maxSatisfied(customers, grumpy, 3) << endl;
    return 0;
}
