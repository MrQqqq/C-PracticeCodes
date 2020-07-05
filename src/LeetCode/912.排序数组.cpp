/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-30 18:19:36
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 18:20:54
 * @FilePath: \cpp\src\LeetCode\912.排序数组.cpp
 */ 
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include<vector>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};
// @lc code=end

