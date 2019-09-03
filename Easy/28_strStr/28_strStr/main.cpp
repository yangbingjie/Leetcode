#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> buildNextVector(string needle){
        vector<int>next(needle.length());
        next[0] = -1;
        int k = -1;
        int j = 0; // 当前部分子串的索引
        while (j < needle.length() - 1) {
            if (k == -1 || needle[k] == needle[j]) {
                next[++j] = ++k;
            }else{
                k = next[k];
            }
        }
        return next;
    }
    // KMP
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        vector<int>next = buildNextVector(needle);
        int i = 0;
        int j = 0;
        while ((i < haystack.length()) && (j < int(needle.length()))) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }else{
                j = next[j];
            }
        }
        return (j == needle.length()) ? i - j : -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("BBCMABCDABMABCDABCDABDE", "ABCDABD") << endl;
    return 0;
}
