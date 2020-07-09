//
//  main.cpp
//  17.13_respace
//
//  Created by bella on 2020/7/9.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int>dp(sentence.size() + 1);
        dp[0] = 0;
        for (int i = 1; i < sentence.size() + 1; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < dictionary.size(); ++j) {
                if (i >= dictionary[j].size() && dictionary[j] == sentence.substr(i - dictionary[j].size(), dictionary[j].size())) {
                    dp[i] = min(dp[i], dp[i - dictionary[j].size()]);
                }
            }
        }
        return dp[sentence.size()];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    string arr[LEN] = {"looked","just","like","her","brother"};
    vector<string> dictionary(arr, arr + LEN);
    cout << s.respace(dictionary, "jesslookedjustliketimherbrother") << endl;
    return 0;
}
