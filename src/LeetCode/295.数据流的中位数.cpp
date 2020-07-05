/*
 * @Description: [295] 数据流的中位数
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-04 20:16:09
 * @LastEditors: szq
 * @LastEditTime: 2020-07-04 20:28:45
 * @FilePath: \cpp\src\LeetCode\295.数据流的中位数.cpp
 */ 
/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class MedianFinder {
public:
    vector<int> nums;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(nums.size() == 0){
            nums.push_back(num);
            return;
        }
        vector<int>::iterator iter = upper_bound(nums.begin(),nums.end(),num);
        nums.insert(iter,num);
    }
    
    double findMedian() {
        int len = nums.size() ;
        if(len % 2 != 0){
            return nums[len / 2];
        }
        return (nums[len / 2 - 1] + nums[len / 2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

