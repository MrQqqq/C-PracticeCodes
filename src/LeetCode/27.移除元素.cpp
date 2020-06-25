/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 04:08:57
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 04:08:57
 * @FilePath: \cpp\src\27.????.cpp
 */ 
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        int length = 0;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] != val){
                nums[length++] = nums[i];
            }
        }
        return length;
    }
};
// @lc code=end

