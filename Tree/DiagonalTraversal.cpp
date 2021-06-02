//Problem Link:- https://www.interviewbit.com/problems/diagonal-traversal/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int level, map<int,vector<int>>& mp){
    if (!root){
        return;
    }
    mp[level].push_back(root->val);
    helper(root->left,level+1,mp);
    helper(root->right,level,mp);
}

vector<int> solve(TreeNode* root){
    vector<int> result;
    if (!root){
        return result;
    }
    map<int,vector<int>> mp;
    helper(root,0,mp);
    for(auto x : mp){
        vector<int> nums = x.second;
        for(auto it=nums.begin();it!=nums.end();it++){
            result.push_back(*it);
        }
    }
    return result;
}