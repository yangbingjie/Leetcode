//
//  main.cpp
//  152_maxProduct
//
//  Created by Bella Yang on 2020/5/12.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int max_n = 1;
        int min_n = 1;
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0){
                swap(max_n, min_n);
            }
            max_n = max(max_n*nums[i], nums[i]);
            min_n = min(min_n*nums[i], nums[i]);
            result = max(result, max_n);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
