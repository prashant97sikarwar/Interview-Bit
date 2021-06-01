//Problem Link:- https://www.interviewbit.com/problems/2sum-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int k, set<int>& s){
    if (!root){
        return 0;
    }
    int val = k - (root->val);
    if (s.find(val) != s.end()){
        return 1;
    }
    s.insert(root->val);
    return helper(root->left,k,s) || helper(root->right,k,s);
}
int t2Sum(TreeNode* root, int k){
    if (!root){
        return 0;
    }
    if (!root->left && !root->right){
        return 0;
    }
    set<int> s;
    return helper(root, k, s);
}
