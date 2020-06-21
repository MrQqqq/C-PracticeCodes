/**
 * 从尾到头打印链表
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 * 示例 1：

    输入：head = [1,3,2]
    输出：[2,3,1]
 * 
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> reversePrint(ListNode* head){
    if(!head){
        return {};
    }
    vector<int> res;
    res=reversePrint(head->next);
    res.push_back(head->val);
    return res;
}