/*
    面试题03. 数组中重复的数字

    找出数组中重复的数字。


    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
    数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个
    数字重复了几次。请找出数组中任意一个重复的数字。

    示例 1：

    输入：
    [2, 3, 1, 0, 2, 5, 3]
    输出：2 或 3 

*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int findRepeatNumber(vector<int>& nums){
    set<int> res_set;
    for(int num : nums){
        if(!res_set.insert(num).second){
            return num;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int res = findRepeatNumber(nums);
    cout << res << endl;
}
