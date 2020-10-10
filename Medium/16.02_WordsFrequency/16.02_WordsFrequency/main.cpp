//
//  main.cpp
//  16.02_WordsFrequency
//
//  Created by Bella Yang on 2020/10/10.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WordsFrequency {
private:
    static const int LEN =26;
    struct Node{
        char ch;
        int num;
        Node * next[LEN];
        Node(char c, int n = 0):ch(c),num(n){
            memset(next, 0, sizeof(next));
        }
    };
    Node * head;
public:
    WordsFrequency(vector<string>& book) {
        head = new Node('?', -1);
        for(int i = 0; i < book.size(); ++i){
            insert(book[i]);
        }
    }
    void insert(const string & word){
        Node * node = head;
        for(int i = 0; i < word.size(); ++i){
            if(!node->next[word[i] - 'a']){
                node->next[word[i] - 'a'] = new Node(word[i]);
            }
            node = node->next[word[i] - 'a'];
        }
        node->num++;
    }
    int get(string word) {
        Node * node = head;
        for(int i = 0; i < word.size(); ++i){
            if(node->next[word[i] - 'a']){
                node = node->next[word[i] - 'a'];
            }else{
                return 0;
            }
        }
        return node->num;
    }
};


int main(int argc, const char * argv[]) {
    vector<string>str = {"i", "have", "an", "apple", "he", "have", "a", "pen"};
    WordsFrequency wordsFrequency(str);
    cout << wordsFrequency.get("you") << endl; //返回0，"you"没有出现过
    cout << wordsFrequency.get("have") << endl; //返回2，"have"出现2次
    cout << wordsFrequency.get("an")<< endl; //返回1
    cout << wordsFrequency.get("apple")<< endl; //返回1
    cout << wordsFrequency.get("pen")<< endl; //返回1
    return 0;
}
