//Problem Link:- https://www.interviewbit.com/problems/right-view-of-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root,map<int,int>& mp,int level){
     if (!root){
         return;
     }
     mp[level] = root->val;
     helper(root->left,mp,level+1);
     helper(root->right,mp,level+1);
 }
 
vector<int> solve(TreeNode* root){
    vector<int> result;
    if (!root){
        return result;
    }
    map<int,int> mp;
    helper(root,mp,0);
    for(auto x : mp){
        result.push_back(x.second);
    }
    return result;
}
