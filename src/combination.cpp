/*
 * @Description: 全组合，利用位图
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-19 14:28:58
 * @LastEditors: szq
 * @LastEditTime: 2020-06-19 15:47:23
 * @FilePath: \cpp\combination.cpp
 */ 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

namespace solution1{
    template<class T>
    void combinate(vector<T> v,int index,int total,vector<T> &path,vector<vector<T>> &res){
        for(int i = 0;i < total;++i){
            if(index >> i & 1 == 1){
                path.push_back(v[i]);
            }
        }
        res.push_back(path);
    }

    template<class T>
    vector<vector<T>> combination(vector<T> v,int count){
        vector<vector<T>> res;
        for(int i = 0; i < (1<<count);++i){
            vector<T> path;
            combinate(v,i,count,path,res);
        }
        return res;
    }
}

//递归解法
namespace solution2{
    template<class T>
    void combination_n(const vector<T> &v,vector<T> &cur_v,int cur_index,int number,vector<vector<T>> &result){
        if(number == 0){
            result.push_back(cur_v);
            return;
        }
        if(cur_index >= v.size()){
            return;
        }
        cur_v.push_back(v[cur_index]);
        combination_n(v,cur_v,cur_index+1,number-1,result);
        cur_v.pop_back();
        combination_n(v,cur_v,cur_index+1,number,result);
    }

    template<class T>
    void combination(const vector<T> &v,vector<vector<T>> &result){
        if(v.empty()){
            return;
        }
        if(v.size() == 1){
            result.push_back(v);
            return;
        }
        vector<T> tmp;
        for(int i =1;i <= v.size();++i){
            combination_n(v,tmp,0,i,result);
        }
    }
}


int main(int argc,char *argv[]){
    const int N = 3;
    vector<int> v = {1,2,3};
    
    //位图版
    vector<vector<int>> res1 = solution1::combination(v,3);
    cout << "位图版：" << endl;
    for(auto nums : res1){
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }


    vector<vector<int>> res2;
    solution2::combination(v,res2);
    cout << "递归版：" <<endl;
    for(auto nums : res2){
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
}