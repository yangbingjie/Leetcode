//
//  main.cpp
//  925_isLongPressedName
//
//  Created by Bella Yang on 2020/10/21.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        int name_count;
        int typed_count;
        char ch;
        while(i < name.size() && j < typed.size()){
            if(name[i] == typed[j]){
                ch = name[i];
                i++;
                j++;
                name_count = 1;
                typed_count = 1;
                while (i < name.size() && name[i] == ch) {
                    i++;
                    name_count++;
                }
                while (j < typed.size() && typed[j] == ch) {
                    j++;
                    typed_count++;
                }
                if (name_count > typed_count) {
                    return false;
                }
            }else{
                return false;
            }
        }
        return i == name.size() && j == typed.size();
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isLongPressedName("saeed", "ssaaedd") << endl;
    return 0;
}
