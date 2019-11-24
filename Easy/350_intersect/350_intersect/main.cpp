//
//  main.cpp
//  350_intersect
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }else if (nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
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
    s.intersect(vec1, vec2);
    return 0;
}
