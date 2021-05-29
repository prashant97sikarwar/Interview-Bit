//Problem Link:- https://www.interviewbit.com/problems/symmetric-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* p, TreeNode* q){
    if (p == NULL && q == NULL){
        return true;
    }
    if (p == NULL || q == NULL){
        return false;
    }
    if (p->val != q->val){
        return false;
    }
    return helper(p->left,q->right) && helper(p->right,q->left);
}
 
int isSymmetric(TreeNode* root){
    if (root == NULL){
            return true;
    }
    if (root->left == NULL && root->right == NULL){
        return true;
    }
    return helper(root->left,root->right);
}