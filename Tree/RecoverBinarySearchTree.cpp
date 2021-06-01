//Problem Link:- https://www.interviewbit.com/problems/recover-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* pre = new TreeNode(INT_MIN);
TreeNode* first = NULL;
TreeNode* second;
 
 void helper(TreeNode* root){
     if (root->left){
         helper(root->left);
     }
     if (first == NULL && root->val < pre->val){
         first = pre;
     }
     if (first != NULL && root->val < pre->val){
         second = root;
     }
     pre = root;
     if (root->right){
         helper(root->right);
     }
 }
 
vector<int> recoverTree(TreeNode* root){
    pre = new TreeNode(INT_MIN);
    first = NULL;
    second = NULL;
    if (!root){
        return {};
    }
    if (!root->left && !root->right){
        return {};
    }
    helper(root);
    vector<int> result;
    result.push_back(first->val);
    result.push_back(second->val);
    sort(result.begin(),result.end());
    return result;
}