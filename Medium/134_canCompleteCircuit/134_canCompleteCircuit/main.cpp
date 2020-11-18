//
//  main.cpp
//  134_canCompleteCircuit
//
//  Created by Bella Yang on 2020/11/18.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int cur_gas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            cur_gas += gas[i] - cost[i];
            total_gas += gas[i] - cost[i];
            if (cur_gas < 0) {
                start = i + 1;
                cur_gas = 0;
            }
        }
        return total_gas < 0 ? -1 : start;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> gas = {3,3,4};
    vector<int> cost = {3,4,4};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
