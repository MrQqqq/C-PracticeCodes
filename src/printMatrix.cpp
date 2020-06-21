/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-09 14:16:28
 * @LastEditors: szq
 * @LastEditTime: 2020-06-09 15:08:45
 * @FilePath: \cpp\printMatrix.cpp
 */ 
#include<vector>
#include<iostream>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    //顶
    int top = 0;
    //底
    int bottom = matrix.size() - 1;
    //左
    int left = 0;
    //右
    int right = matrix[0].size()-1;
    while(top <= bottom && left <= right){
        for(int i = left;i <= right;++i){
            res.push_back(matrix[top][i]);
        }
        ++top;
        if(top > bottom){
            break;
        }
        for(int i = top;i <= bottom;++i){
            res.push_back(matrix[i][right]);
        }
        --right;
        if(left > right){
            break;
        }
        
        for(int i = right;i >= left;--i){
            res.push_back(matrix[bottom][i]);
        }
        --bottom;
        if(top > bottom){
            break;
        }
        for(int i = bottom;i >= top;--i){
            res.push_back(matrix[i][left]);
        }
        ++left;
    }
    return res;

}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    vector<int> res = spiralOrder(matrix);
    
    for(int num : res){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
