//
//  main.cpp
//  85_maximalRectangle
//
//  Created by Bella Yang on 2020/12/26.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
            stack<int>sta;
            int max_area = 0;
            int tmp;
            for (int i = 0; i < heights.size(); ++i) {
                while (!sta.empty() && heights[i] < heights[sta.top()]) {
                    tmp = sta.top();
                    sta.pop();
                    max_area = max(max_area, (i - sta.top() - 1) * heights[tmp]);
                }
                sta.push(i);
            }
            return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int max_rect = 0;
        vector<int>left(matrix[0].size() + 2, 0);
        for (int i = 0; i < matrix.size(); ++i) {
            left[0] = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == '0'){
                    left[j + 1] = 0;
                }else{
                    left[j + 1] += 1;
                }
            }
            left[left.size() - 1] = 0;
            max_rect = max(max_rect, largestRectangleArea(left));
        }
        return max_rect;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<char>> mat = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    Solution s;
    cout << s.maximalRectangle(mat) << endl;
    return 0;
}
