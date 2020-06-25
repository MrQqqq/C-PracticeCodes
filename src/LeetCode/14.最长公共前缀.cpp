/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 10:55:35
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 11:04:23
 * @FilePath: \cpp\src\14.最长公共前缀.cpp
 */ 
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        int i = 0;
        int minlen = INT_MAX;
        for(auto str:strs){
            minlen = str.length() < minlen ? str.length() : minlen;
        }
        while(i < minlen){
            char tmp = strs[0][i];
            for(auto str :strs){
                if(str[i] != tmp){
                    return str.substr(0,i);
                }
            }
            i++;
        }
        return strs[0].substr(0,i);
    }
};
// @lc code=end

