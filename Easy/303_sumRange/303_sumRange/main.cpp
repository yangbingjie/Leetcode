//
//  main.cpp
//  303_sumRange
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class NumArray {
private:
    vector<int> vec;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        vec.push_back(sum);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            vec.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return this->vec[j + 1] - this->vec[i];
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int array[LEN] = {-2, 0, 3, -5, 2, -1};
    vector<int>nums(array, array + LEN);
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0,2) << endl;
    cout << obj->sumRange(2,5) << endl;
    cout << obj->sumRange(0,5) << endl;
    return 0;
}
