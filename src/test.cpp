/*
 * @Description: 一些测试代码
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-14 11:37:24
 * @LastEditors: szq
 * @LastEditTime: 2020-05-15 10:01:25
 * @FilePath: \cpp\test.cpp
 */
#include<iostream>
using namespace std;
struct S1{
    long a;
    char c;
    S1(){
        a = 0;
        c = 'a';
    }
};

/**
 * @destription: 输出结构的大小
 * @param {type} 
 * @return: 
 */
template <class T>
void testStructSizeof(T &t){
    cout << sizeof(t) << endl;
}

/**
 * @destription: 静态成员变量，初始化只有一次，之后不会再初始化。
 * @param {type} 
 * @return: 
 */
void staticFun(){
    static int a = 10;
    a++;
    cout << a << endl;
}
void testStatic(){
    staticFun();
    cout << "---------------" << endl;
    staticFun();
}
#include<vector>
#include<algorithm>
// void testFind(){
//     vector<int> nums = {1,2,3,4,5,6,7,8,9};
//     vector<int>::iterator iter = find(nums.begin(),nums.end(),5);
//     int index = iter - nums.begin();
//     cout << nums[index] << endl;
//     nums.erase(nums.begin());
//     cout << *nums.begin() << endl;
// }

void testErase(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    for(int i = 0;i < 3;i++){
        nums.erase(nums.begin());
    }
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    // S1 *s = new S1();
    
    // cout << sizeof(S1)<<endl;

    // testStatic();

    //测试find函数
    // testFind();

    testErase();
}