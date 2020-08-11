//
//  main.cpp
//  648_replaceWords
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int len;
    Node* children[26];
    Node(int
         is){
        len = is;
        memset(children, NULL, sizeof(children));
    }
};
class Solution {
private:
    Node* root;
public:
    void insertNode(string str){
        Node* node = root;
        for (int i = 0; i < str.size(); ++i) {
            if (node->children[str[i] - 'a'] == NULL) {
                node->children[str[i] - 'a'] = new Node(0);
            }
            node = node->children[str[i] - 'a'];
        }
        node->len = str.size();
    }
    int findStr(string str){
        Node* node = root;
        for (int i = 0; i < str.size(); ++i) {
            if (node->len != 0) {
                return node->len;
            }
            if (node->children[str[i] - 'a'] == NULL) {
                return 0;
            }
            node = node->children[str[i] - 'a'];
        }
        return 0;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        root = new Node(false);
        for (int i = 0; i < dict.size(); ++i) {
            insertNode(dict[i]);
        }
        int len;
        string result = "";
        for (int slow = 0, fast = 0; fast < sentence.size();) {
            while (slow < sentence.size() && sentence[slow] == ' ') {
                slow++;
            }
            fast = slow;
            while (fast < sentence.size() && sentence[fast] != ' ') {
                fast++;
            }
            len = findStr(sentence.substr(slow, fast - slow));
            if (len > 0) {
                result += sentence.substr(slow, len);
            }else{
                result += sentence.substr(slow, fast - slow);
            }
            if (fast < sentence.size()) {
                result += ' ';
            }
            fast++;
            slow = fast;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
    string arr[LEN] = {"cat", "bat", "rat"};
    vector<string>vec(arr, arr + LEN);
    Solution s;
    cout << s.replaceWords(vec, "the cattle was rattled by the battery") << endl;
    return 0;
}
