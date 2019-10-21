//
//  main.cpp
//  169_majorityElement
//
//  Created by Bella Yang on 2019/10/21.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        int max = 0;
        int result = 0;
        for (iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second > max) {
                max = iter->second;
                result = iter->first;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 7;
    int array[LEN] = {2,2,1,1,1,2,2};
    Solution s;
    vector<int>nums(array, array + LEN);
    cout << s.majorityElement(nums) << endl;
    return 0;
}
