//
//  main.cpp
//  Offer05_replaceSpace
//
//  Created by Bella Yang on 2020/10/11.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int count_space = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                count_space++;
            }
        }
        if(count_space == 0){
            return s;
        }
        int ind = s.size() - 1;
        s.resize(s.size() + count_space * 2);
        int new_ind = s.size() - 1;
        while(ind >= 0){
            if(s[ind] != ' '){
                s[new_ind] = s[ind];
                ind--;
                new_ind--;
            }else{
                s[new_ind--] = '0';
                s[new_ind--] = '2';
                s[new_ind--] = '%';
                ind--;
            }
        }
        return s;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.replaceSpace("We are happy.") << endl;
    return 0;
}
