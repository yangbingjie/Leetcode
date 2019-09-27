//
//  main.cpp
//  88_merge
//
//  Created by Bella Yang on 2019/9/27.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = int(nums1.size()) - 1;
        m--;
        n--;
        while (n >= 0 || m >= 0) {
            if (n < 0 || ((n >= 0) && (m >= 0) && nums1[m] > nums2[n])) {
                nums1[index] = nums1[m];
                index--;
                m--;
            }else if (m < 0 || ((n >= 0) && (m >= 0) && nums1[m] < nums2[n])){
                nums1[index] = nums2[n];
                index--;
                n--;
            }else{
                nums1[index] = nums1[m];
                index--;
                m--;
                nums1[index] = nums2[n];
                index--;
                n--;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 6;
    const int LEN2 = 3;
    int array1[LEN1] = {4, 5, 6};
    int array2[LEN2] = {2, 5, 6};
    vector<int> nums1 (array1, array1 + LEN1);
    vector<int> nums2 (array2, array2 + LEN2);
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    return 0;
}
