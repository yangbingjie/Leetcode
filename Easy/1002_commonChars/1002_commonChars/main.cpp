//
//  main.cpp
//  1002_commonChars
//
//  Created by Bella Yang on 2020/10/14.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int>min_count(26, 0);
        for(int j = 0; j < A[0].size(); ++j){
            min_count[A[0][j] - 'a']++;
        }        
        for(int i = 0; i < A.size(); ++i){
            vector<int>current(26, 0);
            for(int j = 0; j < A[i].size(); ++j){
                current[A[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (min_count[j] > current[j]) {
                    min_count[j] = current[j];
                }
            }
        }
        vector<string>result;
        for (int j = 0; j < 26; ++j) {
            while (min_count[j] != 0) {
                result.push_back(string(1, j + 'a'));
                min_count[j]--;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<string> A = {"bella","label","roller"};
    Solution s;
    s.commonChars(A);
    return 0;
}
