/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 04:14:17
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 04:17:46
 * @FilePath: \cpp\src\307.区域和检索-数组可修改.cpp
 */ 
/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> numArray;
    NumArray(vector<int>& nums) {
        numArray = nums;
    }
    
    void update(int i, int val) {
        numArray[i] = val;
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        while(i <= j && i < numArray.size()){
            res += numArray[i];
            i++;
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

