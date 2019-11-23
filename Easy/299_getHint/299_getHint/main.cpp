//
//  main.cpp
//  299_getHint
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
        }
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
        for (int i = 0, j = 0; i < secret.size() && j < secret.size();) {
            if (secret[i] == guess[j]) {
                i++;
                j++;
                cows++;
            }else if (secret[i] < guess[j]){
                i++;
            }else{
                j++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows - bulls) + "B";
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.getHint("18072314", "78105216") << endl;
    return 0;
}
