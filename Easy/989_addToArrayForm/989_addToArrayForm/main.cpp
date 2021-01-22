//
//  main.cpp
//  989_addToArrayForm
//
//  Created by Bella Yang on 2021/1/22.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        int i = A.size() - 1;
        int reminder, sum;
        for(; i >= 0; --i){
            reminder = K % 10;
            K = (K - reminder) / 10;
            sum = reminder + A[i] + carry;
            A[i] = sum % 10;
            carry = (sum - A[i]) / 10;
        }
        sum = carry + K;
        while (sum != 0){
            reminder = sum % 10;
            A.insert(A.begin(), reminder);
            sum = (sum - reminder) / 10;
        }
        return A;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> A = {9,9,9};
    Solution s;
    s.addToArrayForm(A, 9999);
    return 0;
}
