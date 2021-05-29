//Problem Link:- https://www.interviewbit.com/problems/invert-the-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root){
    if (root == NULL){
        return NULL;
    }
    TreeNode* right = invertTree(root->right);
    TreeNode* left = invertTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}