/*
 * @Description: 测试C++set容器
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-13 20:08:42
 * @LastEditors: szq
 * @LastEditTime: 2020-05-14 03:11:21
 * @FilePath: \cpp\testSet.cpp
 */


#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    
    s.insert(1);
    s.insert(2);
    cout << *s.begin() << endl;
    s.erase(1);
    cout << *s.begin() << endl;
    cout << s.size() << endl;
}