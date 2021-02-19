//
//  main.cpp
//  1004_longestOnes
//
//  Created by Bella Yang on 2021/2/19.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int result = K;
        int slow = 0;
        int fast = 0;
        int k = K;
        while (fast < A.size()) {
            if (A[fast] == 0) {
                if (k <= 0) {
                    break;
                }
                k--;
            }
            fast++;
        }
        while (fast < A.size()) {
            result = max(result, fast - slow);
            if (A[fast] == 0) {
                while (k == 0) {
                    if (A[slow] == 0) {
                        k++;
                    }
                    slow++;
                }
                k--;
            }
            fast++;
        }
        return max(result, fast - slow);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> A = {1,1,1,0,0,0,1,1,1,1};
    Solution s;
    cout << s.longestOnes(A, 0) << endl;
    return 0;
}
