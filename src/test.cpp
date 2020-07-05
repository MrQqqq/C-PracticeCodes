/*
 * @Description: 一些测试代码
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-14 11:37:24
 * @LastEditors: szq
 * @LastEditTime: 2020-06-30 19:08:23
 * @FilePath: \cpp\src\test.cpp
 */
// #include<iostream>
// using namespace std;
// struct S1{
//     long a;
//     char c;
//     S1(){
//         a = 0;
//         c = 'a';
//     }
// };

// /**
//  * @destription: 输出结构的大小
//  * @param {type} 
//  * @return: 
//  */
// template <class T>
// void testStructSizeof(T &t){
//     cout << sizeof(t) << endl;
// }

// /**
//  * @destription: 静态成员变量，初始化只有一次，之后不会再初始化。
//  * @param {type} 
//  * @return: 
//  */
// void staticFun(){
//     static int a = 10;
//     a++;
//     cout << a << endl;
// }
// void testStatic(){
//     staticFun();
//     cout << "---------------" << endl;
//     staticFun();
// }
// #include<vector>
// #include<algorithm>
// // void testFind(){
// //     vector<int> nums = {1,2,3,4,5,6,7,8,9};
// //     vector<int>::iterator iter = find(nums.begin(),nums.end(),5);
// //     int index = iter - nums.begin();
// //     cout << nums[index] << endl;
// //     nums.erase(nums.begin());
// //     cout << *nums.begin() << endl;
// // }

// void testErase(){
//     vector<int> nums = {1,2,3,4,5,6,7,8,9};
//     for(int i = 0;i < 3;i++){
//         nums.erase(nums.begin());
//     }
//     for(int num : nums){
//         cout << num << " ";
//     }
//     cout << endl;
// }

// void testSubstr(){
//     string s = "III";
//     cout << s.substr(0,2).c_str() << endl;
// }

// bool valid(string s){
//     int balance = 0;
//     for(char c : s){
//         if(c == '('){
//             balance++;
//         }
//         else{
//             balance--;
//             if(balance < 0){
//                 return false;
//             }
//         }
//     }
//     if(balance == 0){
//         return true;
//     }
//     return false;
// }
// void dfs(string &s,int cur,vector<string> &res){
//     if(cur == s.length()){
//         if(valid(s)){
//             res.push_back(s);
//         }
//         return;
//     }
//     s[cur] = '(';
//     dfs(s,cur+1,res);
//     s[cur] = ')';
//     dfs(s,cur + 1,res);
// }
// vector<string> generateParenthesis(int n) {
//     vector<string> res;
//     if(n == 0){
//         return res;
//     }
//     string s(n * 2,'(');
//     dfs(s,0,res);
//     return res;
// }


// int strStr(string haystack, string needle) {
//     if(needle == ""){
//         return 0;
//     }
//     int i = 0;
//     int len_needle = needle.length();
//     int count = haystack.length() - len_needle;
//     while(i <= count){
//         if(haystack[i] == needle[0]){
//             int j = i;
//             int k = 0;
//             while(k < len_needle){
//                 if(haystack[j] != needle[k]){
//                     break;
//                 }
//                 j++;
//                 k++;
//             }
//             if(k == len_needle){
//                 return i;
//             }
//         }
//         i++;
//     }
//     return -1;
// }


// string simplifyPath(string path) {
//     vector<string> v;
//     while(path.length() > 0){
//         int index = path.find("/");
//         string str;
//         if(index == -1){
//             str = path;
//             if(str == ".." && v.size() > 0){
//                 v.pop_back();
//             }
//             else if(str != "" && str != "." && str !=".."){
//                 v.push_back(str);
//             }
//             break;
//         }
//         else{
//             str = path.substr(0,index);
//             if(str == ".." && v.size() > 0){
//                 v.pop_back();
//             }
//             else if(str != "" && str != "." && str !=".."){
//                 v.push_back(str);
//             }
//             path = path.substr(index+1);
//         }
        
        
//     }
//     if(v.size() == 0){
//         return "/";
//     }
//     string res = "";
//     for(auto s : v){
//         res += "/";
//         res += s;
//     }
//     return res;
// }


// bool valid1(string s){
//     return s >= "0" && s <= "255";
// }


#include<iostream>
#include<vector>
using namespace std;
bool valid(string s){
    if (s.size() > 1 && s[0] == '0')
    {
        return false;
    }
    
    int res = atoi(s.c_str());
    return res >= 0 && res <= 255;
}
void dfs(int index,int pre,string &s,vector<string> &res){
    if(index == 4 && valid(s.substr(pre))){
        res.push_back(s);
        return;
    }
    else if(index == 4){
        return;
    }
    else{
        for(int j = 1;j < 4 && pre + j < s.length(); j++){
            string cur = s.substr(pre,j);
            if(valid(cur)){
                s.insert(s.begin() + pre + j,'.');
                dfs(index+1,pre+j+1,s,res);
                s.erase(s.begin()+pre+j);
            }
            else{
                return;
            }
            
        }

    }
    
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.length() < 4){
        return res;
    }
    dfs(1,0,s,res);
    return res;
    
}


int calculate(string s) {
    vector<int> nums;
    vector<string> ops;
    int i = 0;
    int len = s.size();
    while(i < len){
        string tmp;
        if(s[i] >= '0' && s[i] <= '9'){

            while(i < len && s[i] >= '0' && s[i] <= '9'){
                tmp += s[i];
                i++;
            }
            nums.push_back(atoi(tmp.c_str()));
        }
        else if(s[i] == ' '){
            i++;
        }
        else{
            tmp += s[i];
            i++;
            ops.push_back(tmp);
        }
    }
    for(int i = 0;i < ops.size();){
        if(ops[i] == "*"){
            int res = nums[i] * nums[i+1];
            nums.erase(nums.begin() + i,nums.begin() + i + 2);
            nums.insert(nums.begin() + i,res);
            ops.erase(ops.begin() + i);
        }
        else if(ops[i] == "/"){
            int res = nums[i] / nums[i+1];
            nums.erase(nums.begin() + i,nums.begin() + i + 2);
            nums.insert(nums.begin() + i,res);
            ops.erase(ops.begin() + i);
        }
        else{
            i++;
        }
    }
    while(ops.size() > 0){
        if(ops[0] == "+"){
            int res = nums[0] + nums[1];
            nums.erase(nums.begin(),nums.begin() + 2);
            nums.insert(nums.begin(),res);
            ops.erase(ops.begin());
        }
        else if(ops[0] == "-"){
            int res = nums[0] - nums[1];
            nums.erase(nums.begin(),nums.begin() + 2);
            nums.insert(nums.begin(),res);
            ops.erase(ops.begin());
        }
    }
    return nums[0];
}


int wiggleMaxLength(vector<int>& nums) {
    if(nums.size() < 2){
        return nums.size();
    }
    int flag = 0;
    int count = 1;
    int j = 1;
    while(j < nums.size()){
        if(nums[j - 1] == nums[j]){
            j++;
        }
        else{
            flag = nums[j - 1] > nums[j];
            j++;
            count++;
            break;
        }
    }
    while(j < nums.size()){
        if(nums[j - 1] != nums[j] && flag ^ nums[j - 1] > nums[j] == 1){
            count++;
            flag = nums[j] < nums[j - 1];
            j++;
        }
        else{
            j++;
        }
    }
    return count;
}
int main(){
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    cout << wiggleMaxLength(nums) << endl;
}