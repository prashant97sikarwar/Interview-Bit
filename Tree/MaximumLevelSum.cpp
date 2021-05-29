//Problem Link:- https://www.interviewbit.com/problems/maximum-level-sum/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int solve(TreeNode* root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
        return root->val;
    }
    queue<TreeNode*> pq;
    pq.push(root);
    int sm = 0,mxsm = INT_MIN;
    while (!pq.empty()){
        int sz = pq.size();
        sm = 0;
        while (sz--){
            TreeNode* node = pq.front();
            pq.pop();
            sm += node->val;
            if (node->left){
                pq.push(node->left);
            }
            if (node->right){
                pq.push(node->right);
            }
        }
        if (sm > mxsm){
            mxsm = sm;
        }
    }
    return mxsm;
}
