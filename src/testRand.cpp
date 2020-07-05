/*
 * @Description: 测试C++中随机数
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-13 03:01:51
 * @LastEditors: szq
 * @LastEditTime: 2020-07-05 10:18:23
 * @FilePath: \cpp\src\testRand.cpp
 */
#include<iostream>
// #include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

/**
 * @destription: 获取N个随机数
 * @param {int}:随机数的个数
 * @return: 返回产生的N个随机数的数组
 */
vector<int> getNRandNumber(int n){
    vector<int> res;
    //设置随机数种子
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n;++i){
        //生成随机数
        res.push_back(rand());
    }
    return res;
}
int main(){
    //生成十个随机数
    vector<int> res = getNRandNumber(10);
    //输出生成的随机数
    for(auto rand_num : res){
        cout << rand_num << "\t";
    }
    cout << endl;
    return 0;
}