//
//  main.cpp
//  1189_maxNumberOfBalloons
//
//  Created by Bella Yang on 2020/1/4.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(3, 0);
        int l = 0;
        int o = 0;
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == 'b') {
                v[0]++;
            }else if (text[i] == 'a'){
                v[1]++;
            }else if (text[i] == 'n'){
                v[2]++;
            }else if (text[i] == 'l'){
                l++;
            }else if (text[i] == 'o'){
                o++;
            }
        }
        int singles = *min_element(v.begin(), v.end());
        int doubles =  (int)(((l > o) ? o : l) / 2);
        return min(singles, doubles);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.maxNumberOfBalloons("naebolko") << endl;
    return 0;
}
