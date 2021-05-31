//Problem Link:- https://www.interviewbit.com/problems/remove-half-nodes/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solve(TreeNode* root){
    if (!root){
        return NULL;
    }
    root->left = solve(root->left);
    root->right = solve(root->right);
    
    if (root->left == NULL && root->right == NULL){
        return root;
    }
    if (root->left == NULL){
        TreeNode* new_node = root->right;
        free(root);
        return new_node;
    }
    if (root->right == NULL){
        TreeNode* new_node = root->left;
        free(root);
        return new_node;
    }
    return root;
}
