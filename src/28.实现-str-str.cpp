/*
 * @Description: ???????strStr()
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-26 09:55:32
 * @LastEditors: szq
 * @LastEditTime: 2020-06-26 10:19:48
 * @FilePath: \cpp\src\28.??-str-str.cpp
 */ 
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        int i = 0;
        int len_needle = needle.length();
        int count = haystack.length() - len_needle;
        while(i <= count){
            if(haystack[i] == needle[0]){
                int j = i;
                int k = 0;
                while(k < len_needle){
                    if(haystack[j++] != needle[k]){
                        break;
                    }
                }
                if(k == len_needle){
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

