/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-09 01:42:30
 * @LastEditors: szq
 * @LastEditTime: 2020-06-09 01:43:44
 * @FilePath: \cpp\jump2.cpp
 */ 
#include<iostream>
using namespace std;

int numWays(int n) {
        
    if(n <= 1){
        return 1;
    }
    int *arr = new int(n+1);
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2;i <= n;++i){
        arr[i] = arr[i-1] + arr[i-2];
    } 
    return arr[n];

}

int main(){
    int res = numWays(7);
    cout << res <<endl;
}