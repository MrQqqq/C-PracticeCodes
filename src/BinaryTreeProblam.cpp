/*
 * @Description: 二叉树相关题目
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-03 11:59:20
 * @LastEditors: szq
 * @LastEditTime: 2020-06-03 12:41:26
 * @FilePath: \cpp\BinaryTreeProblam.cpp
 */ 

/**
 * @destription: 根据一棵树的中序遍历与后序遍历构造二叉树。
 * @param inorder:中序遍历数组   postorder:后序遍历数组
 * @return: 二叉树根节点
 */
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        if(inorder.size() == 0){
            return root;
        }
        int value = postorder.back();
        postorder.pop_back();
        root = new TreeNode(value);
        auto iter = find(inorder.begin(),inorder.end(),value);
        vector<int> rightinorder = vector<int>(iter+1,inorder.end());
        vector<int> leftinorder = vector<int>(inorder.begin(),iter);
        root->right = buildTree(rightinorder,postorder);
        root->left = buildTree(leftinorder,postorder);
        return root;
    }
};