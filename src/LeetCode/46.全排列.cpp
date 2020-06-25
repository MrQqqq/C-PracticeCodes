/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 01:07:16
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 01:22:05
 * @FilePath: \cpp\src\46.全排列.cpp
 */ 
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void permutation1(vector<int> &nums,int cur,const int size,vector<vector<int>> &res){
        if(cur == size - 1){
            res.push_back(nums);
            return;
        }
        for(int i = cur;i < size;++i){
            swap(nums[cur],nums[i]);
            permutation1(nums,cur+1,size,res);
            swap(nums[cur],nums[i]);
        }
    }

    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            res.push_back(nums);
        }
        return res;
    }
};
// @lc code=end

