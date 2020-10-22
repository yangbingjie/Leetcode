//
//  main.cpp
//  763_partitionLabels
//
//  Created by Bella Yang on 2020/10/22.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>arr(26);
        for (int i = 0; i < S.size(); ++i) {
            arr[S[i] - 'a'] = i;
        }
        vector<int> result;
        int last_ind = 0;
        int ind = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (arr[S[i] - 'a'] > ind) {
                ind = arr[S[i] - 'a'];
            }
            if (ind == i) {
                ind++;
                result.push_back(ind - last_ind);
                last_ind = ind;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}
