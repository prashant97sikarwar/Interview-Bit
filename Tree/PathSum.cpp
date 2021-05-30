//Problem Link:- https://www.interviewbit.com/problems/path-sum/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int hasPathSum(TreeNode* root, int target){
    if (!root){
        return false;
    }
    int remsm = target - root->val;
    if (remsm == 0 && root->left == NULL && root->right == NULL){
        return true;
    }
    return hasPathSum(root->left,remsm) || hasPathSum(root->right,remsm);
}