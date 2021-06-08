//Problem Link:- https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int ans = INT_MIN;
int helper(TreeNode* root){
    if (!root){
        return 0;
    }
    if (!root->left && !root->right){
        ans = max(ans,root->val);
        return root->val;
    }
    int left = 0, right = 0;
    if (root->left){
        left = max(helper(root->left), left);
    }
    if (root->right){
        right = max(helper(root->right), right);
    }
    ans =  max(ans, left + right + root->val);
    return max(left,right) + root->val;
}
 
int maxPathSum(TreeNode* root){
    ans = INT_MIN;
    if (!root){
        return root->val;
    }
    if (!root->left && !root->right){
        return root->val;
    }
    helper(root);
    return ans;
}
