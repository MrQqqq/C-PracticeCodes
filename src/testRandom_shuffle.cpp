/*
 * @Description: 测试algorithm中的random_shuffle函数
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-13 03:28:32
 * @LastEditors: szq
 * @LastEditTime: 2020-05-13 03:42:45
 * @FilePath: \笔记c:\Users\86151\Desktop\cpp\testRandom_shuffle.cpp
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @destription: 产生一个1-n数组成的不重复的随机序列
 * @param {int}:数组的长度
 * @return: 生成的随机数组
 */
vector<int> getRandomArray(int n){
    vector<int> res;
    for(int i = 1;i <= n;i++){
        res.push_back(i);
    }
    random_shuffle(res.begin(),res.end());
    return res;
}

int main(){
    vector<int> random_nums = getRandomArray(10);
    for(auto random_num : random_nums){
        cout << random_num << "\t";
    }
    cout << endl;
    return 0;
}