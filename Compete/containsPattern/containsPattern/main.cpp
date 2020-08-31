//
//  main.cpp
//  containsPattern
//
//  Created by bella on 2020/8/30.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        bool flag;
        for (int i = 0; i < arr.size(); ++i) {
            count = 1;
            for (int j = i + m; j < arr.size();j+=m) {
                flag = true;
                for (int s = 0; s < m; ++s) {
                    if (j + s >= arr.size() || arr[i + s] != arr[j + s]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }else{
                    break;
                }
            }
            if (count >= k) {
                return true;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int arr[LEN] = {2,2,2,2};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.containsPattern(vec, 2, 3) << endl;
    return 0;
}
