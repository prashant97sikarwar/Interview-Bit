//Problem Link:- https://www.interviewbit.com/problems/max-depth-of-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int maxDepth(TreeNode* root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);
}
