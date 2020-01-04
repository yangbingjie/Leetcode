//
//  main.cpp
//  929_numUniqueEmails
//
//  Created by Bella Yang on 2020/1/4.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string::iterator iter;
        string::iterator tmp;
        for (int i = 0; i < emails.size(); ++i) {
            iter = emails[i].begin();
            while (iter != emails[i].end()) {
                if (*iter == '@') {
                    break;
                }else if (*iter == '.'){
                    emails[i].erase(iter);
                }else if (*iter == '+'){
                    tmp = find(emails[i].begin(), emails[i].end(), '@');
                    emails[i].erase(iter, tmp);
                    break;
                }
                iter++;
            }
        }
        int num = (emails.size() != 0);
        sort(emails.begin(), emails.end());
        for (int i = 0; i < emails.size() - 1; ++i) {
            if (emails[i] != emails[i + 1]) {
                num++;
            }
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
    string array[LEN] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    vector<string>v(array, array + LEN);
    Solution s;
    cout << s.numUniqueEmails(v) << endl;
    return 0;
}
