//
//  main.cpp
//  941_validMountainArray
//
//  Created by Bella Yang on 2020/11/3.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3){
            return false;
        }
        int left = 1;
        while (left < A.size() && A[left - 1] < A[left]) {
            left++;
        }
        int right = A.size() - 2;
        while (right >= 0 && A[right] > A[right + 1]) {
            right--;
        }
        return left != A.size() && right + 1 != 0 && left - 1 == right + 1;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> A = {0,1,2,3,5,6,7,8,9};
    cout << s.validMountainArray(A) << endl;
    return 0;
}
