//
//  main.cpp
//  649_predictPartyVictory
//
//  Created by Bella Yang on 2020/12/11.
//

#include <iostream>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        if (senate.size() == 1) {
            return senate[0] == 'R' ? "Radiant" : "Dire";;
        }
        int slow = 0;
        int fast = 1;
        int kill = 0;
        int diff = 0;
        int i;
        while (kill < senate.size()) {
            i = 0;
            while (senate[slow] == senate[fast] || senate[fast] == 'M') {
                i++;
                if (i == senate.size()) {
                    return senate[slow] == 'R' ? "Radiant" : "Dire";
                }
                fast = (fast + 1) % senate.size();
            }
            if (senate[fast] == 'R') {
                diff++;
            }else{
                diff--;
            }
            senate[fast] = 'M';
            kill++;
            slow = (slow + 1) % senate.size();
            while (senate[slow] == 'M') {
                slow = (slow + 1) % senate.size();
            }
            fast = (slow + 1) % senate.size();
        }
        return diff < 0 ? "Radiant" : "Dire";
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.predictPartyVictory("D") << endl;
    return 0;
}
