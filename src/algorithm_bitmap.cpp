/*
 * @Description: bitmap算法实现
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-14 03:14:05
 * @LastEditors: szq
 * @LastEditTime: 2020-05-14 03:32:26
 * @FilePath: \cpp\algorithm_bitmap.cpp
 */
#include<iostream>
#include<cstring>
using namespace std;

#define SHIFT 5
#define MASK 0x1F

/**
 * @destription: 设置所在的bit位为1
 * @param {int}：目标数    {int*}:bit数组 
 * @return: 无
 */

void set(int n,int *arr){
    int index_loc;//在bit数组中的位置
    int bit_loc;//在bit数组元素中bit位
    index_loc = n >> 5;//相当于n / 32
    bit_loc = n & MASK;//相当于 n % 32
    arr[index_loc] |= 1 << bit_loc;
}

int test(int n,int *arr){
    int i,flag;
    i = 1 << (n&MASK);
    flag = arr[n >> SHIFT] & i;
    return flag;
}

int main(){
    int i,num,space,*arr;
    while(cin >> num){
        space = num >> SHIFT + 1;
        arr = (int*)malloc(sizeof(int) * space);
        memset(arr,0,sizeof(arr));
        set(num,arr);
        if(test(num,arr)){
            cout <<"success!" << endl;
        }
        else{
            cout << "failed!" <<endl;
        }
        delete(arr);
    }
}
