//
//  main.cpp
//  336_palindromePairs
//
//  Created by bella on 2020/8/6.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node {
    Node* children[26];
    int ind;
    Node(int index=-1){
        ind = index;
        memset(children, 0, sizeof(children));
    }
};
class Solution {
public:
    bool isPalindrome(string& str, int left, int right){
        for (int i = 0; left + i < right - i; ++i) {
            if (str[left + i] != str[right - i]) {
                return false;
            }
        }
        return true;
    }
    void insertWord(Node*root, string str, int ind){
        Node* node = root;
        for (int i = str.size() - 1; i >= 0; --i) {
            if (node->children[str[i] - 'a'] == NULL) {
                node->children[str[i] - 'a'] = new Node();
            }
            node = node->children[str[i] - 'a'];
        }
        node->ind = ind;
    }
    int findWords(Node* root, string &str, int start, int end){
        Node* node = root;
        for (int i = start; i < end; ++i) {
            if (node->children[str[i] - 'a'] == NULL) {
                return -1;
            }
            node = node->children[str[i] - 'a'];
        }
        return node->ind;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        Node* root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            insertWord(root, words[i], i);
        }
        vector<int>tmp(2);
        int ind;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                if (isPalindrome(words[i], j, words[i].size() - 1)) {
                    ind = findWords(root, words[i], 0, j);
                    if (-1 != ind && ind != i) {
                        tmp[0] = i;
                        tmp[1] = ind;
                        result.push_back(tmp);
                    }
                }
                if (j && isPalindrome(words[i], 0, j - 1)) {
                    ind = findWords(root, words[i], j, words[i].size());
                    if (-1 != ind && ind != i) {
                        tmp[0] = ind;
                        tmp[1] = i;
                        result.push_back(tmp);
                    }
                }
            }
        }
        return  result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
    string arr[LEN]={"abcd","dcba","lls","s","sssll"};
    vector<string>vec(arr, arr + LEN);
    Solution s;
    s.palindromePairs(vec);
    return 0;
}
