//
//  main.cpp
//  Offer45_minNumber
//
//  Created by Bella Yang on 2020/10/26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(string str1, string str2){
        return str1 + str2 < str2 + str1;
    }
    string minNumber(vector<int>& nums) {
        vector<string> vec(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            vec[i] = to_string(nums[i]);
        }
        sort(vec.begin(), vec.end(), compare);
        string str = "";
        for (int i = 0; i < nums.size(); ++i) {
            str += vec[i];
        }
        return str;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,30,34,5,9};
    Solution s;
    cout << s.minNumber(nums) << endl;
    return 0;
}
