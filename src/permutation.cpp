/*
 * @Description: 全排列
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-19 09:39:06
 * @LastEditors: szq
 * @LastEditTime: 2020-06-19 14:28:24
 * @FilePath: \cpp\permutation.cpp
 */ 


#include <iostream>
#include <vector>
 
using namespace std;
 
 namespace solution1{

    /*
        方案1：递归法
            通过交换位置来实现，未去重
    */
     //交换
    template<class T>
    void Swap(T &a ,T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    
    /**
     * @destription: 全排列
     * @param {type} 
     * @return: 
     */ 
    template<class T>
    void ALLRange(vector<T> &v, int cur, const int size, vector<vector<T>> &result){
        if(cur==size-1){
            result.push_back(v);
            return;
        }else{
            for(int i=cur; i<=size-1; i++){

                //从下标为cur的元素开始，分别与它后面的元素交换
                Swap(v[cur],v[i]);
                ALLRange(v,cur+1,size,result);
                //复位
                Swap(v[cur],v[i]);
                
                
            }
        }
        return;
    }

    /**
     * @destription: 全排列的调用函数
     * @param {type} 
     * @return: 
     */ 
    template<class T>
    void Permutation(const vector<T> &v, vector<vector<T>> &result){
        vector<T> v2(v);
    
        if(v.empty()){
            return;
        }else if(v.size()==1){
            result.push_back(v);
        }else{
            ALLRange(v2, 0, v2.size(), result);
        }
    }
    
    
    // int main(int argc, char *argv[])
    // {
    //     vector<int> v{1,2,3,3};
    //     vector<vector<int>> result;
    //     Permutation(v,result);
    
    //     for(auto a:result){
    //         for(auto b:a){
    //             cout<<b;
    //         }
    //         cout<<endl;
    //     }
    
    //     return 0;
    // }
 }



/**
 * @destription: 利用STL中algorithm库中prev_permutation函数和
 *                  next_permutation函数找全排列
 * @param {type} 
 * @return: 
 */
#include<algorithm>
int main(){
    int arr[] = {2,1,0};
    do{
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    }
    while(prev_permutation(arr,arr+3));
    int arr1[] = {0,1,2};
    do{
        cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl;
    }
    while(next_permutation(arr1,arr1+3));
    return 0;
}
 