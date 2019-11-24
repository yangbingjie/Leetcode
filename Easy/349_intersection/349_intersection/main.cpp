//
//  main.cpp
//  349_intersection
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (result.empty() || nums1[i] != result[result.size() - 1]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }else if (nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        while (i != nums1.size()) {
            if (nums1[i] == nums2[j - 1] && (result.empty() || nums1[i] != result[result.size() - 1])) {
                result.push_back(nums1[i]);
            }
            i++;
        }
        while (j != nums2.size()) {
            if (nums1[i - 1] == nums2[j] && (result.empty() || nums2[j] != result[result.size() - 1])) {
                result.push_back(nums2[j]);
            }
            j++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 2;
    const int LEN2 = 9;
    int array1[LEN1] = {9, 1};
    int array2[LEN2] = {7,8,3,9,0,0,9,1,5};
    vector<int>vec1(array1, array1 + LEN1);
    vector<int>vec2(array2, array2 + LEN2);
    Solution s;
    s.intersection(vec1, vec2);
    return 0;
}
