//
//  main.cpp
//  1588_sumOddLengthSubarrays
//
//  Created by Bella Yang on 2020/10/7.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        for (int i = 0; i < arr.size(); ++i) {
            result += arr[i] * (((i + 1) / 2) * ((arr.size() - i) / 2) + (i / 2 + 1) * ((arr.size() - i + 1) / 2));
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>arr = {1,4,2,5,3};
    Solution s;
    cout << s.sumOddLengthSubarrays(arr) << endl;
    return 0;
}
