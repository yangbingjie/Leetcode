/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (49.31%)
 * Likes:    9002
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        multimap<int, int>nums_map;
        for (int i = 0; i < nums.size(); ++i) {
            nums_map.insert(pair<int, int>(nums[i], i));
        }
        multimap<int, int>::iterator i = nums_map.begin();
        multimap<int, int>::iterator j = --nums_map.end();

        while (i != j) {
            int sum = i->first + j->first;
            if (sum == target) {
                if (i->second < j->second) {
                    result.push_back(i->second);
                    result.push_back(j->second);
                }else{
                    result.push_back(j->second);
                    result.push_back(i->second);
                }
                return result;
            }else if (sum < target){
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
};
// @lc code=end
