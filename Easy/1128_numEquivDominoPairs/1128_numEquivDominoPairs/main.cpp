//
//  main.cpp
//  1128_numEquivDominoPairs
//
//  Created by Bella Yang on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
        }
        sort(dominoes.begin(), dominoes.end(), [](vector<int>& vec1, vector<int>& vec2){
            return vec1[0] < vec2[0] || (vec1[0] == vec2[0] && vec1[1] < vec2[1]);
        });
        int num = 0;
        int count = 1;
        for (int i = 1; i <= dominoes.size(); ++i) {
            if (i != dominoes.size() && dominoes[i] == dominoes[i - 1]) {
                count++;
            }else{
                if (count > 1) {
                    num += count * (count - 1) / 2;
                }
                count = 1;
            }
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> dominoes = {{2,1},{5,4},{3,7},{6,2},{4,4},{1,8},{9,6},{5,3},{7,4},{1,9},{1,1},{6,6},{9,6},{1,3},{9,7},{4,7},{5,1},{6,5},{1,6},{6,1},{1,8},{7,2},{2,4},{1,6},{3,1},{3,9},{3,7},{9,1},{1,9},{8,9}};
    Solution s;
    cout << s.numEquivDominoPairs(dominoes) << endl;
    return 0;
}
