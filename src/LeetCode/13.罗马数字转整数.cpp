/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 10:17:37
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 10:48:39
 * @FilePath: \cpp\src\13.罗马数字转整数.cpp
 */ 
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<string,int> m = {
            {"I",1},
            {"IV",4},
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900}
        };
        int res = 0;
        for(int i = 0;i < s.length();++i){
            if(s[i] == 'I' || s[i] == 'X' || s[i] == 'C' && i < s.length() - 1){
                string sub = s.substr(i,2);
                if(m.find(s.substr(i,2)) != m.end()){
                    res += m[sub];
                    ++i;
                    continue;
                }
            }
            res += m[s.substr(i,1)];
        }
        return res;
    }
};
// @lc code=end

