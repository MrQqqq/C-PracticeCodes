/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 03:26:52
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 03:32:45
 * @FilePath: \cpp\src\1.????.cpp
 */ 
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0;i < nums.size() - 1;++i){
            for(int j = i+1;j < nums.size();++j){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

