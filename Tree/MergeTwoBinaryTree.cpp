//Problem Link:- https://www.interviewbit.com/problems/merge-two-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solve(TreeNode* root1, TreeNode* root2){
    if (!root1){
        return root2;
    }
    if (!root2){
        return root1;
    }
    root1->val += root2->val;
    root1->left = solve(root1->left,root2->left);
    root1->right = solve(root1->right,root2->right);
    return root1;
}
