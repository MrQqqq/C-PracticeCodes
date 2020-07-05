/*
 * @Description: 堆排序
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-04 21:01:47
 * @LastEditors: szq
 * @LastEditTime: 2020-07-04 22:14:52
 * @FilePath: \cpp\src\heapsort.cpp
 */ 

#include<iostream>
#include<queue>
using namespace std;

/**
 * @destription： 调整堆
 * @param :nums：待调整的堆   i:调整的当前非叶子节点   length:数组长度
 * @return: 没有返回值
 */
void adjustHeap(vector<int> &nums,int i,int length){
    int temp = nums[i];//取出当前元素
    for(int k = i * 2 + 1;k < length;k = k * 2 + 1){//从i节点的左子节点开始，也就是2i+1出开始
        if(k + 1 < length && nums[k] < nums[k+1]){//如果左子节点小于右子节点，k指向右子节点
            k++;
        }
        //如果子节点大于父节点，将子节点的值赋给父节点(不用交换)
        if(nums[k] > temp){
            nums[i] = nums[k];
            i = k;
        }
        else{
            break;
        }
    }
    nums[i] = temp;//将父节点的值放在最终的位置
}

/**
 * @destription: 交换数组中i,j位置的值
 * @param {type} nums:要交换的数组   i、j:位置
 * @return: 没有返回值
 */
void swap(vector<int> &nums,int i,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

/**
 * @destription: 堆排序函数
 * @param {type} nums:待排序数组
 * @return: 没有返回值
 */
void heapsort(vector<int> &nums){
    int len = nums.size();
    //构建大根堆
    for(int i = len/2 - 1;i >= 0;i--){
        adjustHeap(nums,i,len);
    }

    //交换对顶元素与末尾元素，并调整堆
    for(int i = len - 1;i > 0;i--){
        swap(nums,0,i);
        adjustHeap(nums,0,i);
    }
}

int main(){
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    heapsort(nums);
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
}