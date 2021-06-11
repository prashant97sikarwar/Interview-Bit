//Problem Link:- https://www.interviewbit.com/problems/level-order/

#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if (!root){
        return result;
    }
    queue<TreeNode*> pq;
    pq.push(root);
    while (!pq.empty()){
        int sz = pq.size();
        vector<int> temp;
        while (sz--){
            TreeNode* node = pq.front();
            temp.push_back(node->val);
            pq.pop();   
            if (node->left){
                pq.push(node->left);
            }
            if (node->right){
                pq.push(node->right);
            }
        }
        result.push_back(temp);
    }
    return result;
}
