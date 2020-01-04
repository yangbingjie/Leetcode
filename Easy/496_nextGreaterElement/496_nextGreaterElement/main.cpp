//
//  main.cpp
//  496_nextGreaterElement
//
//  Created by Bella Yang on 2020/1/4.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2;
        int value;
        while(iter1 != nums1.end()){
            iter2 = find(nums2.begin(), nums2.end(), *iter1);
            value = -1;
            iter2++;
            while(iter2 != nums2.end()){
                if(*iter2 > *iter1){
                    value = *iter2;
                    break;
                }
                iter2++;
            }
            result.push_back(value);
            iter1++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 2;
    const int LEN2 = 4;
    int array1[LEN1] = {2,4};
    int array2[LEN2] = {1,2,3,4};
    vector<int>vec1(array1, array1 + LEN1);
    vector<int>vec2(array2, array2 + LEN2);
    s.nextGreaterElement(vec1, vec2);
    return 0;
}
