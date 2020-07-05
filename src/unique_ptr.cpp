/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 15:29:20
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 15:35:11
 * @FilePath: \cpp\src\unique_ptr.cpp
 */ 
#include<iostream>

using namespace std;

int main(){
    unique_ptr<string> p1(new string("hello world!"));
    // unique_ptr<string> p2;
    // p2 = p1;//报错，独占式拥有。防止p3不再指向有效数据
    unique_ptr<string> p2 = unique_ptr<string>(new string("hello world!"));//右值是一个临时变量，允许
    cout << (*p1).c_str() <<endl;
    cout << (*p2).c_str() <<endl;
    return 0;
}