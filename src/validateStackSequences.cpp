/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-10 02:05:33
 * @LastEditors: szq
 * @LastEditTime: 2020-06-10 02:35:28
 * @FilePath: \cpp\validateStackSequences.cpp
 */ 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> tmp;
    int i = 0;
    int j = 0;
    while(i < pushed.size()){
        tmp.push_back(pushed[i]);
        ++i;
        while(tmp.size() > 0 && tmp.back() == popped[j]){
            tmp.pop_back();
            ++j;
        }
    }
    if(tmp.size() == 0){
        return true;
    }
    return false;
}

int main(){
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    cout << validateStackSequences(pushed,popped) << endl;
    return 0;
}
