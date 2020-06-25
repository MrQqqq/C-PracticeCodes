/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 00:34:49
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 00:37:03
 * @FilePath: \cpp\src\35.搜索插入位置.cpp
 */ 
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0;i < nums.size();++i){
            if(nums[i] >= target){
                return i;
            }
        }
        return nums.size();
    }
};
// @lc code=end

