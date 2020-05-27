//
//  main.cpp
//  974_subarraysDivByK
//
//  Created by Bella Yang on 2020/5/27.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int, int>m;
        map<int, int>::iterator iter;
        int tmp = 0;
        for (int i = 0; i < A.size(); ++i) {
            tmp += A[i];
            tmp %= K;
            if (tmp < 0) {
                tmp += K;
            }
            iter = m.find(tmp);
            if (iter != m.end()) {
                iter->second++;
            }else{
                m[tmp] = 1;
            }
        }
        int count = 0;
        iter = m.begin();
        while (iter!=m.end()) {
            count += (iter->second * (iter->second - 1))/2;
            if (iter->first == 0) {
                count += iter->second;
            }
            iter++;
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int arr[LEN] = {4,5,0,-2,-3,1};
    vector<int>A(arr, arr + LEN);
    Solution s;
    cout << s.subarraysDivByK(A, 7) << endl;
    return 0;
}
