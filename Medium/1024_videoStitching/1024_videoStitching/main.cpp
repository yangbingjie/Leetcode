//
//  main.cpp
//  1024_videoStitching
//
//  Created by Bella Yang on 2020/10/24.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static bool compare(vector<int>v1, vector<int>v2){
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), compare);
        if (clips[0][0] != 0) {
            return -1;
        }
        vector<int>dp(T, INT_MAX);
        int i = 0;
        while (i + 1 < clips.size() && clips[i + 1][0] == 0) {
            i++;
        }
        if (i < clips.size()) {
            if(clips[i][1] - 1 < T){
                dp[clips[i][1] - 1] = 1;
            }else{
                dp[T - 1] = 1;
            }
        }
        i++;
        while (i < clips.size()) {
            while(i + 1 < clips.size() && clips[i + 1][0] == clips[i][0]){
                i++;
            }
            for (int j = clips[i][0] - 1; j < clips[i][1] && j < dp.size(); j++) {
                if (dp[j] != INT_MAX) {
                    if(clips[i][1] - 1 < T){
                        dp[clips[i][1] - 1] = min(dp[clips[i][1] - 1], dp[j] + 1);
                    }else{
                        dp[T - 1] = min(dp[T - 1], dp[j] + 1);
                    }
                }
            }
            i++;
        }
        return dp[T - 1] != INT_MAX ? dp[T - 1] : -1;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>clips = {{0,4},{2,8}};
    Solution s;
    cout << s.videoStitching(clips, 5) << endl;
    return 0;
}
