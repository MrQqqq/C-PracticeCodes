/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-08 13:54:56
 * @LastEditors: szq
 * @LastEditTime: 2020-06-11 02:20:11
 * @FilePath: \cpp\StringSplit.cpp
 */ 
#include<iostream>
#include<vector>
using namespace std;

vector<string> StringSplit(string src,char c){
    vector<string> res;
    while(src != ""){
        int index = src.find(c);
        if(index > 0){
            res.push_back(src.substr(0,index));
            src = src.substr(index+1);
        }
        else if(index == 0){
            src = src.substr(index+1);
        }
        else{
            res.push_back(src);
            break;
        }
    }
    return res;
}

int main(){
    string s = "  the sky is blue ";
    vector<string> res = StringSplit(s,' ');
    for(string str : res){
        cout << str.c_str() << endl;
    }
    string s1 = "123456";
    s1 = s1.substr(1,5);
    cout << s1.c_str() << endl;
    return 0;
}