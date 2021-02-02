//
//  main.cpp
//  424_characterReplacement
//
//  Created by Bella Yang on 2021/2/2.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        vector<int>arr(26, 0);
        int fast = 0;
        int slow = 0;
        while (fast < s.size()) {
            arr[s[fast] - 'A']++;
            result = max(result, arr[s[fast] - 'A']);
            if (fast - slow + 1 > result + k) {
                arr[s[slow] - 'A']--;
                slow++;
            }
            fast++;
        }
        return s.size() - slow;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.characterReplacement("AABCABBB", 2) << endl;
    return 0;
}
