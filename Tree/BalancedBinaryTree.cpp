//Problem Link:- https://www.interviewbit.com/problems/balanced-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int,bool> helper(TreeNode* root){
     if (!root){
         return {0,true};
     }
     if (!root->left && !root->right){
         return {1,true};
     }
     pair<int,bool> lh = helper(root->left);
     pair<int,bool> rh = helper(root->right);
     int h = max(lh.first,rh.first) + 1;
     bool flag = lh.second && rh.second && (abs(lh.first - rh.first) <= 1);
     return {h,flag};
 }
 
int isBalanced(TreeNode* root){
    if (!root){
        return true;
    }
    if (!root->left && !root->right){
        return true;
    }
    pair<int,bool> x = helper(root);
    if (x.second){
        return 1;
    }
    return 0;
}
