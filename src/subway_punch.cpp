/*
 * @Description: 乐鑫科技2020秋招笔试题2
 *                  地铁打卡活动
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-30 03:14:02
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 03:56:52
 * @FilePath: \cpp\src\subway_punch.cpp
 */ 

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n,m,a,b;//n:地铁站点数   m：连通的地铁站点数 a:地铁最低票价 b:非地铁方式票价

    cin >> n >> m >> a >> b;//输入

    vector<set<int>> res;
    for(int i = 0;i < m; ++i){
        int start,des;
        cin >> start >> des;
        
        int flag = 1;
        for(int j = 0;j < res.size();++j){
            if(res[j].find(start) != res[j].end()|| res[j].find(des) != res[j].end()){
                res[j].insert(start);
                res[j].insert(des);
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            set<int> s;
            s.insert(start);
            s.insert(des);
            res.push_back(s);
        }
    }
    int count = 0;
    for(auto tmp_set : res){
        count += tmp_set.size();
    }
    cout << (n - count + res.size() + 1) * b + res.size() * a << endl;;


}
