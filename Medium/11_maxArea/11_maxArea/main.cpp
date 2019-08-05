//
//  main.cpp
//  11_maxArea
//
//  Created by Bella Yang on 2019/8/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int temp_area = 0;
        int start = 0;
        int end = int(height.size() - 1);
        
        while (start < end) {
            temp_area = (end - start) * min(height[start], height[end]);
            if (temp_area > max_area) {
                max_area = temp_area;
            }
            if (height[start] < height[end]) {
                start++;
            }else{
                end--;
            }
        }
        
        return max_area;
    }
};

//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int max_area = 0;
//        int temp_area = 0;
//        for (int i = 1; i < height.size(); ++i) {
//            for (int j = 0; j < i; ++j) {
//                temp_area = (i - j) * min(height[j], height[i]);
//                if (temp_area > max_area) {
//                    max_area = temp_area;
//                }
//            }
//        }
//        return max_area;
//    }
//};

int main(int argc, const char * argv[]) {
    Solution s;
    const int len = 9;
    int array[len] = {1,8,6,2,5,4,8,3,7};
    vector<int> vec(array, array + len);
    cout << s.maxArea(vec) << endl;
    return 0;
}
