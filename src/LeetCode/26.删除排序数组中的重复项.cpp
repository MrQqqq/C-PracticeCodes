/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 04:01:38
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 04:06:28
 * @FilePath: \cpp\src\26.删除排序数组中的重复项.cpp
 */ 
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int duplicate = nums[0];
        int length = 1;
        int next;
        for(int i = 1;i < nums.size();++i){
            if(nums[i] != duplicate){
                nums[length++] = nums[i];
                duplicate = nums[i];
            }
        }
        return length;
    }
};
// @lc code=end

