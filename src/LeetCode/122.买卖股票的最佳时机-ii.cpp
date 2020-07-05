/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-30 18:35:49
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 18:35:49
 * @FilePath: \cpp\src\LeetCode\122.买卖股票的最佳时机-ii.cpp
 */ 
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1;i < prices.size();++i){
            profit += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }
        return profit;
    }
};
// @lc code=end

