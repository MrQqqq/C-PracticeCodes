/**
 * 面试题07. 重建二叉树
    输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    例如，给出

    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：

        3
    / \
    9  20
        /  \
    15   7
 * 
 * **/

#include <vector>
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
    //查找根节点在中序遍历数组中的位置
    int findRoot(int val,vector<int> inorder){
        int i = 0;
        for(int num : inorder){
            if(num == val){
                return i;
            }
            i++;
        }
        return i;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归结束条件，中序或者前序数组为空
        if(inorder.size() == 0 || preorder.size() == 0){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int>::iterator it = preorder.begin();
        //先序数组中删除第一个节点
        preorder.erase(it);
        int index = findRoot(root->val,inorder);
        //将中序序列分成左子树中序序列和右子树中序序列
        vector<int> l(inorder.begin(),inorder.begin()+index);
        vector<int> r(inorder.begin()+index+1,inorder.end());
        //递归创建左子树和右子树
        root->left = buildTree(preorder,l);
        root->right = buildTree(preorder,r);
        
        return root;

    }
};
