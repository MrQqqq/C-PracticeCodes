/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-28 18:11:19
 * @LastEditors: szq
 * @LastEditTime: 2020-06-28 19:04:12
 * @FilePath: \cpp\src\LeetCode\71.简化路径.cpp
 */ 
/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        while(path.length() > 0){
            int index = path.find("/");
            string str;
            if(index == -1){
                str = path;
                if(str == ".." && v.size() > 0){
                    v.pop_back();
                }
                else if(str != "" && str != "." && str !=".."){
                    v.push_back(str);
                }
                break;
            }
            else{
                str = path.substr(0,index);
                if(str == ".." && v.size() > 0){
                    v.pop_back();
                }
                else if(str != "" && str != "." && str !=".."){
                    v.push_back(str);
                }
                path = path.substr(index+1);
            }
            
            
        }
        if(v.size() == 0){
            return "/";
        }
        string res = "";
        for(auto s : v){
            res += "/";
            res += s;
        }
        return res;
    }
};
// @lc code=end

