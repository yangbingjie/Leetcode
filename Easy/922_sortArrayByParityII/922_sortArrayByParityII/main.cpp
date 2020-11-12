//
//  main.cpp
//  922_sortArrayByParityII
//
//  Created by Bella Yang on 2020/11/12.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        while (i < A.size() && j < A.size()) {
            while (i < A.size() && A[i] % 2 == 0) {
                i += 2;
            }
            while (j < A.size() && A[j] % 2 == 1) {
                j += 2;
            }
            if (i < A.size() && j < A.size()) {
                swap(A[i], A[j]);
                i += 2;
                j += 2;
            }
        }
        return A;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> a = {2,3};
    Solution s;
    s.sortArrayByParityII(a);
    return 0;
}
