/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 12:36:35
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 12:57:35
 * @FilePath: \cpp\src\121.买卖股票的最佳时机.cpp
 */ 
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

