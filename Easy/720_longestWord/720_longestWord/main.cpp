//
//  main.cpp
//  720_longestWord
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node {
    int ind;
    bool has_child;
    Node* children[26];
    Node(){
        ind = -1;
        has_child = false;
        memset(children, 0, sizeof(children));
    }
};
class Solution {
private:
    Node* root;
    string str;
public:
    void insertNode(string str, int i){
        Node* node = root;
        for (int i = 0; i < str.size(); ++i) {
            if (node->children[str[i] - 'a'] == NULL) {
                node->children[str[i] - 'a'] = new Node();
            }
            node->has_child = true;
            node = node->children[str[i] - 'a'];
        }
        node->ind = i;
    }
    void findStr(Node* node, vector<string>& words){
        if(node->ind != -1 && str.size() < words[node->ind].size()){
            str = words[node->ind];
        }
        for(int i = 0; i < 26; ++i){
            if((node == root || node->ind != -1) && node->children[i] != NULL){
                findStr(node->children[i], words);
            }
        }
    }
    string longestWord(vector<string>& words) {
        root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            insertNode(words[i], i);
        }
        str = "";
        findStr(root, words);
        return str;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 16;
//    string arr[LEN] = {"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"};
    string arr[LEN] = {"ogz","eyj","e","ey","hmn","v","hm","ogznkb","ogzn","hmnm","eyjuo","vuq","ogznk","og","eyjuoi","d"};

    vector<string> vec(arr, arr + LEN);
    Solution s;
    cout << s.longestWord(vec) << endl;
    return 0;
}
