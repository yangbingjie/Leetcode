//
//  main.cpp
//  315_countSmaller
//
//  Created by bella on 2020/7/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
using namespace std;
class Solution {
public:
    int lowbit(int x){
        return x & (-x);
    }
    void update(int i, vector<int>&C){
        while (i < C.size()) {
            C[i]++;
            i += lowbit(i);
        }
    }
    void query(int i, int j, vector<int>&C, vector<int>&counts){
        while (i >= 1) {
            counts[j] += C[i];
            i -= lowbit(i);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>counts(nums.size(), 0);
        if (nums.size() < 1) {
            return counts;
        }
        
        vector<int>N(nums);
        // Sort and unique
        sort(N.begin(), N.end());
        int slow = 1;
        int fast = 1;
        while(fast< N.size()) {
            if (N[fast] != N[slow - 1]) {
                N[slow] = N[fast];
                slow++;
                fast++;
            }else{
                fast++;
            }
        }
        N.resize(slow);
        
        // key: number, value: i
        map<int, int>m;
        for (int j = 1; j < 1 + N.size(); ++j) {
            m[N[j - 1]] = j;
        }
        
        // traverse
        vector<int>C(N.size() + 1, 0); //  C[i] is necessary, but A[i] not
        int i;
        for (int j = nums.size() - 1; j >= 0; --j) {
            i = m[nums[j]];
            update(i, C);
            if (i != 1) {
                query(i - 1, j, C, counts);
            }else{
                counts[j] = 0;
            }
        }
        return counts;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 8;
    int arr[LEN] = {7, 5, 6, 5, 2, 6, 5, 1};
    vector<int>vec(arr, arr + LEN);
    s.countSmaller(vec);
    return 0;
}
