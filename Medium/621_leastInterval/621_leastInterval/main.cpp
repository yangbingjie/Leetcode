//
//  main.cpp
//  621_leastInterval
//
//  Created by Bella Yang on 2020/12/5.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>arr(26, 0);
        for (int i = 0; i < tasks.size(); ++i) {
            arr[tasks[i] - 'A']++;
        }
        int max_exec = 0;
        int task_num = 0;
        for (int i = 0; i < 26; ++i) {
            if (arr[i] != 0) {
                if (max_exec < arr[i]) {
                    max_exec = arr[i];
                    task_num = 1;
                }else if (max_exec == arr[i]){
                    task_num++;
                }
            }
        }
        return max(static_cast<int>(tasks.size()), (max_exec - 1) * (n + 1) + task_num);
    }
};
int main(int argc, const char * argv[]) {
    vector<char> vec = {'A','A','A','B','B','B'};
    Solution s;
    cout << s.leastInterval(vec, 0) << endl;
    return 0;
}
