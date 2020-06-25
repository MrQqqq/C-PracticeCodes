/*
 * @Description: C++中四种cast转换
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 13:48:17
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 14:00:01
 * @FilePath: \cpp\src\cast.cpp
 */ 


#include<iostream>
using namespace std;

int main(){
    const int a = 1;
    int& b = const_cast<int&>(a);
    b = a;
    cout << b << endl;
}