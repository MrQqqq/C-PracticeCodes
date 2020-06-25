/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 02:35:01
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 02:39:11
 * @FilePath: \cpp\src\YanghuiTrangle.cpp
 */ 
/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 02:18:40
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 02:32:51
 * @FilePath: \cpp\118.杨辉三角.cpp
 */ 
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1;i <= numRows;++i){
            vector<int> nums(i);
            for(int j = 0;j < i;++j){
                if(j == 0 || j == i - 1){
                    nums[j] = 1;
                }
                else{
                    nums[j] = res[i - 2][j - 1] + res[i - 2][j];
                }
            }
            res.push_back(nums);
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<vector<int>> res;
    res = s.generate(5);
    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
}
// @lc code=end

