//
//  main.cpp
//  5495_mostVisited
//
//  Created by bella on 2020/8/23.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>nums(n, 0);
        int j = -1;
        for(int i = 0; i < rounds.size() - 1; ++i){
            for(j = rounds[i] - 1; j != rounds[i + 1] - 1;){
                nums[j]++;
                j++;
                j %= n;
            }
        }
        if (j != -1) {
            nums[j]++;
        }
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int>result;
        for(int i = 0; i < n; ++i){
            if(max_num == nums[i]){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int arr[LEN] = {1,3,5,7};
    vector<int>rounds(arr, arr + LEN);
    Solution s;
    s.mostVisited(7, rounds);
    return 0;
}
