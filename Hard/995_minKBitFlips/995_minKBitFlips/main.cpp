//
//  main.cpp
//  995_minKBitFlips
//
//  Created by Bella Yang on 2021/2/18.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int result = 0;
        int flips = 0;
        for (int i = 0; i < A.size();++i) {
            if (i >= K && A[i - K] > 1) {
                flips ^= 1;
                A[i - K] -= 2;
            }
            if (A[i] == flips) {
                A[i] += 2;
                flips ^= 1;
                if (i + K > A.size()) {
                    return -1;
                }
                ++result;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>A = {0,0,0,1,0,1,1,0};
    Solution s;
    cout << s.minKBitFlips(A, 3) << endl;
    return 0;
}
