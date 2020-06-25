/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 11:07:47
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 11:22:38
 * @FilePath: \cpp\src\20.有效的括号.cpp
 */ 
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> res;
        map<char,char> m = {{')','('},{']','['},{'}','{'}};
        int i = 0;
        while(i < s.size()){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(res.size() > 0 && res.back() == m[s[i]]){
                    res.pop_back();
                }
                else{
                    return false;
                }
            }
            else{
                res.push_back(s[i]);
            }
            ++i;
        }
        if(res.size() == 0){
            return true;
        }

        return false;
    }
};
// @lc code=end

