/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-30 18:39:16
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 19:06:20
 * @FilePath: \cpp\src\LeetCode\376.摆动序列.cpp
 */ 
/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        int flag = 0;
        int count = 1;
        int j = 1;
        while(j < nums.size()){
            if(nums[j - 1] == nums[j]){
                j++;
                continue;
            }
            else{
                flag = nums[j - 1] > nums[j];
                j++;
                count++;
                break;
            }
        }
        while(j < nums.size()){
            if(nums[j - 1] != nums[j] && flag ^ nums[j - 1] > nums[j] == 1){
                count++;
                flag = nums[j] < nums[j - 1];
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};
// @lc code=end

