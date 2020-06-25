/*
 * @Description: >
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 11:35:13
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 12:17:40
 * @FilePath: \cpp\src\22.括号生成.cpp
 */ 
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    bool valid(string s){
        int balance = 0;
        for(char c : s){
            if(c == '('){
                balance++;
            }
            else{
                balance--;
                if(balance < 0){
                    return false;
                }
            }
        }
        if(balance == 0){
            return true;
        }
        return false;
    }
    void dfs(string &s,int cur,vector<string> &res){
        if(cur == s.length()){
            if(valid(s)){
                res.push_back(s);
            }
            return;
        }
        s[cur] = '(';
        dfs(s,cur+1,res);
        s[cur] = ')';
        dfs(s,cur + 1,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0){
            return res;
        }
        string s(n * 2,'(');
        dfs(s,0,res);
        return res;
    }
};

// int main(){
//     Solution sol;
//     vector<string> res = sol.generateParenthesis(3);
//     return 0;
// }
// @lc code=end

