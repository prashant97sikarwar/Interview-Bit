//Problem Link:- https://www.interviewbit.com/problems/min-depth-of-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root){
    if (!root){
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    if (root->left == NULL){
        return 1 + minDepth(root->right);
    }
    if (root->right == NULL){
        return 1 + minDepth(root->left);
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}