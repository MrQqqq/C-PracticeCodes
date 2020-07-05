/*
 * @Description: 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-30 17:26:22
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 18:12:38
 * @FilePath: \cpp\src\LeetCode\227.基本计算器-ii.cpp
 */ 
/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<string> ops;
        int i = 0;
        int len = s.size();
        while(i < len){
            string tmp;
            if(s[i] >= '0' && s[i] <= '9'){

                while(i < len && s[i] >= '0' && s[i] <= '9'){
                    tmp += s[i];
                    i++;
                }
                nums.push_back(atoi(tmp.c_str()));
            }
            else if(s[i] == ' '){
                i++;
            }
            else{
                tmp += s[i];
                ops.push_back(tmp);
                i++;
            }
        }
        for(int i = 0;i < ops.size();){
            if(ops[i] == "*"){
                int res = nums[i] * nums[i+1];
                nums.erase(nums.begin() + i,nums.begin() + i + 2);
                nums.insert(nums.begin() + i,res);
                ops.erase(ops.begin() + i);
            }
            else if(ops[i] == "/"){
                int res = nums[i] / nums[i+1];
                nums.erase(nums.begin() + i,nums.begin() + i + 2);
                nums.insert(nums.begin() + i,res);
                ops.erase(ops.begin() + i);
            }
            else{
                i++;
            }
        }
        while(ops.size() > 0){
            if(ops[0] == "+"){
                int res = nums[0] + nums[1];
                nums.erase(nums.begin(),nums.begin() + 2);
                nums.insert(nums.begin(),res);
                ops.erase(ops.begin());
            }
            else if(ops[0] == "-"){
                int res = nums[0] - nums[1];
                nums.erase(nums.begin(),nums.begin() + 2);
                nums.insert(nums.begin(),res);
                ops.erase(ops.begin());
            }
        }
        return nums[0];
    }
};
// @lc code=end

