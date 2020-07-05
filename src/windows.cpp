/*
 * @Description: 模拟windows窗口点击
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-30 02:56:47
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 02:57:01
 * @FilePath: \cpp\src\windows.cpp
 */ 
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> windows(N);
    vector<vector<int>> clicks(M);
    for(int i = 0;i < N;++i){
        int xi,yi,wi,hi;
        cin >> xi >> yi >> wi >> hi;
        windows[i].push_back(xi);
        windows[i].push_back(yi);
        windows[i].push_back(wi);
        windows[i].push_back(hi);
        windows[i].push_back(i+1);
    }
    for(int i = 0; i < M; ++i){
        int xi,yi;
        cin >> xi >> yi;
        clicks[i].push_back(xi);
        clicks[i].push_back(yi);
    }
    
    for(int i = 0;i < M;++i){
        int j;
        for(j = N - 1;j >= 0;--j){
            if(clicks[i][0] >= windows[j][0] && clicks[i][0] <= windows[j][0] + windows[j][2] 
              && clicks[i][1] >= windows[j][1] && clicks[i][1] <= windows[j][1] + windows[j][3]){
                cout << windows[j][4] << endl;
                vector<int> window = windows[j];
                windows.erase(windows.begin() + j);
                windows.push_back(window);
                break;
            }
        }
        if(j < 0){
            cout << -1 << endl;
        }
    }
}