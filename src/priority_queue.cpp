/*
 * @Description: 使用priotity_queue实现大（小）根堆
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-04 22:16:41
 * @LastEditors: szq
 * @LastEditTime: 2020-07-04 22:32:38
 * @FilePath: \cpp\src\priority_queue.cpp
 */ 
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int main(){
    //创建大根堆的两种方式

    //1.基本数据类型默认是大根堆
    priority_queue<int> pq1;
    //2.标准格式
    priority_queue<int,vector<int>,less<int>> pq2;//less是比较前一个元素和后一个元素的结果，
                                                    //less小于的意思，因此整个队列是逆序的

    //大根堆里添加元素
    pq1.push(1);
    pq1.push(2);
    pq2.push(1);
    pq2.push(2);

    //测试大根堆顶部元素，大根堆顶部的元素为队列中最大的元素
    cout << "大根堆pq1顶部元素为：" << pq1.top() << endl;
    cout << "大根堆pq2顶部元素为：" << pq2.top() << endl;


    //创建小根堆的方式
    priority_queue<int,vector<int>,greater<int>> pq3;//greater是比较前一个元素和后一个元素的结果，
                                                    //greater大于的意思，因此整个队列是顺序的
    //向小根堆中添加元素
    pq3.push(1);
    pq3.push(2);
    //测试小根堆顶部元素,小根堆顶部的元素为队列中最小的元素
    cout <<"小根堆pq3顶部元素为：" << pq3.top() << endl;

}