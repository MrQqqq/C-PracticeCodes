/**
 * 面试题04. 二维数组中的查找
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排
 * 序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入
 * 这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 示例:

    现有矩阵 matrix 如下：

    [
    [1,   4,  7, 11, 15],
    [2,   5,  8, 12, 19],
    [3,   6,  9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
    ]
    给定 target = 5，返回 true。

    给定 target = 20，返回 false。

*/

#include<iostream>
#include<vector>
using namespace std;
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0||matrix[0].size()==0){
        return false;
    }
    int row = 0;
    int col = matrix[0].size() - 1;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << findNumberIn2DArray(matrix,5) <<endl;
    cout << findNumberIn2DArray(matrix,20) << endl;
}