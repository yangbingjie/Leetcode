//
//  main.cpp
//  1287_findSpecialInteger
//
//  Created by bella on 2020/7/18.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int num = arr.size() / 4;
        int fast = 1;
        int slow = 0;
        while (fast < arr.size()) {
            if (arr[fast] != arr[slow]) {
                slow++;
                fast++;
                if (fast - slow > num) {
                    break;
                }
            }else{
                fast++;
            }
        }
        return arr[slow];
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 8;
    int array[LEN]= {1,2,2,6,6,6,7,10};
    vector<int>vec(array, array + LEN);
    Solution s;
    cout << s.findSpecialInteger(vec) << endl;
    return 0;
}
