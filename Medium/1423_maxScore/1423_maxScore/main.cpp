//
//  main.cpp
//  1423_maxScore
//
//  Created by Bella Yang on 2021/2/6.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int slow = 0;
        int fast = cardPoints.size() - k;
        int score = 0;
        for (int i = 0; i < fast; ++i) {
            score += cardPoints[i];
        }
        int min_score = score;
        while (fast < cardPoints.size()) {
            score -= cardPoints[slow];
            score += cardPoints[fast];
            min_score = min(min_score, score);
            slow++;
            fast++;
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), -min_score);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> cardPoints = {1,1000,1};
    Solution s;
    cout << s.maxScore(cardPoints, 1) << endl;
    return 0;
}
