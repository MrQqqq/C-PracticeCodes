/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-28 19:14:31
 * @LastEditors: szq
 * @LastEditTime: 2020-06-28 20:20:46
 * @FilePath: \cpp\src\LeetCode\93.复原ip地址.cpp
 */ 
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool valid(string s){
        if(s.size() > 1 && s[0] == '0'){
            return false;
        }
        int res = atoi(s.c_str());
        return res >= 0 && res <= 255;
    }
    void dfs(int index,int pre,string &s,vector<string> &res){
        if(index == 4 && valid(s.substr(pre))){
            res.push_back(s);
            return;
        }
        else if(index == 4){
            return;
        }
        else{
            for(int j = 1;j < 4 && pre + j < s.length(); j++){
                string cur = s.substr(pre,j);
                if(valid(cur)){
                    s.insert(s.begin() + pre + j,'.');
                    dfs(index+1,pre+j+1,s,res);
                    s.erase(s.begin()+pre+j);
                }
                else{
                    return;
                }
                
            }

        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() < 4){
            return res;
        }
        dfs(1,0,s,res);
        return res;
        
    }
};
// @lc code=end

