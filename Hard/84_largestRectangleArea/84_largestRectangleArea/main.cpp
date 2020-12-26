//
//  main.cpp
//  84_largestRectangleArea
//
//  Created by Bella Yang on 2020/12/26.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>sta;
        int max_area = 0;
        int tmp;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
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
};
int main(int argc, const char * argv[]) {
    vector<int> heights = {2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
