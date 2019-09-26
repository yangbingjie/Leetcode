//
//  main.cpp
//  167_twoSum
//
//  Created by Bella Yang on 2019/9/26.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        int sum;
        for (int i = 0, j = int(numbers.size()) - 1; j >= 0 && i < numbers.size() && i < j;) {
            sum = numbers[i] + numbers[j];
            if (sum == target) {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }else if (sum > target){
                j--;
            }else{
                i++;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int array[LEN] = {2, 7, 11, 15};
    vector<int> numbers (array, array + LEN);
    Solution s;
    s.twoSum(numbers, 9);
    return 0;
}
