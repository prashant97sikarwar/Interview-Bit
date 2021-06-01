//Problem Link:- https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(vector<vector<int>>& result, vector<int>path,TreeNode* root,int target){
    if (!root){
        return;
    }
    target -= root->val;
    path.push_back(root->val);
    if (!root->left && !root->right && target == 0){
        result.push_back(path);
        return;
    }
    helper(result,path,root->left,target);
    helper(result,path,root->right,target);
    path.pop_back();
    target += root->val;
}

vector<vector<int>> pathSum(TreeNode* root, int target){
    vector<vector<int>> result;
    if (!root){
        return result;
    }
    vector<int> path;
    helper(result,path,root,target);
    return result;
}
