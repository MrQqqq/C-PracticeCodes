/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-24 03:41:11
 * @LastEditors: szq
 * @LastEditTime: 2020-06-24 03:50:19
 * @FilePath: \cpp\src\4.寻找两个正序数组的中位数.cpp
 */ 
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> allNums;
        int l1 = nums1.size();
        int l2 = nums2.size();
        int length = l1 + l2;
        //先合并
        while(nums1.size() > 0 && nums2.size() > 0){
            if(nums1.front() < nums2.front()){
                allNums.push_back(nums1.front());
                nums1.erase(nums1.begin());
            }
            else{
                allNums.push_back(nums2.front());
                nums2.erase(nums2.begin());
            }
        }
        while(nums1.size() > 0){
            allNums.push_back(nums1.front());
            nums1.erase(nums1.begin());
        }
        while(nums2.size() > 0){
            allNums.push_back(nums2.front());
            nums2.erase(nums2.begin());
        }
        if(length % 2 == 0){
            return (allNums[length / 2 - 1] + allNums[length / 2]) / 2.0;
        }
        else{
            return allNums[length / 2];
        }
    }
};
// @lc code=end

