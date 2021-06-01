//Problem Link:- https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root,int value, int &res){
    if (!root){
        return;
    }
    value = (10*value)%1003;
    value = (value + root->val)%1003;
    if (!root->left && !root->right){
        res = (res + value)%1003;
        return;
    }
    helper(root->left,value,res);
    helper(root->right,value,res);
    value /= 10;
}
int  sumNumbers(TreeNode* root){
    if (!root){
        return 0;
    }
    if (!root->left && !root->right){
        return root->val;
    }
    int res = 0;
    helper(root,0,res);
    return res%1003;
}