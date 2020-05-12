#include <iostream>
#include<queue>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        vector<vector<int>> res;
        int node_num = 1;
        while(nodeQue.size()){
            vector<int> tmp;
            int tmp_node = 0;
            for(int i = 0;i < node_num;++i){
                if(root->left){
                    nodeQue.push(root->left);
                    ++tmp_node;
                }
                if(root->right){
                    nodeQue.push(root->right);
                    ++tmp_node;
                }
                tmp.push_back(root->val);
                root = nodeQue.front();
                nodeQue.pop();
            }
            res.push_back(tmp);
            node_num = tmp_node;
            
        }
        return res;
    }
};


int main(){
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Solution S = Solution();
    vector<vector<int>> res = S.levelOrder(node1);
    for(auto tmp : res){
        for (auto ele : tmp){
            cout << ele <<" ";
        }
        cout <<endl;
    }
    return 0;
}