//
//  main.cpp
//  697_findShortestSubArray
//
//  Created by Bella Yang on 2020/5/22.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <typename T1, typename T2>
struct great_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int>m;
        map<int, int>::iterator iter;
        map<int, pair<int, int> > pos;
        map<int, pair<int, int> >::iterator p_iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = m.find(nums[i]);
            if (iter != m.end()) {
                iter->second++;
                p_iter = pos.find(nums[i]);
                p_iter->second.second = i;
            }else{
                m[nums[i]] = 1;
                pos[nums[i]] = pair<int, int>(i, i);
            }
        }
        vector<pair<int, int> >mapcopy(m.begin(), m.end());
        sort(mapcopy.begin(), mapcopy.end(), great_second<int, int>());
        vector<pair<int, int> >::iterator it = mapcopy.begin();
        int count = it->second;
        int min_len = nums.size();
        int tmp;
        while (it != mapcopy.end() && it->second == count) {
            tmp = pos[it->first].second - pos[it->first].first + 1;
            if (tmp < min_len) {
                min_len = tmp;
            }
            it++;
        }
        return min_len;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
//    int arr[LEN] = {1};
//    int arr[LEN] = {1,2,2,3,1,4,2};
    int arr[LEN] = {1, 2, 2, 3, 1};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    cout << s.findShortestSubArray(nums) <<endl;
    return 0;
}
