//Problem Link:- https://www.interviewbit.com/problems/reverse-level-order/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int GetDepth(TreeNode* root){
    if (!root){
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    return max(GetDepth(root->left), GetDepth(root->right)) + 1;
} 

void helper(vector<vector<int>> &result,TreeNode* root,int depth,int level){
    if (!root){
        return;
    }
    result[depth-level-1].push_back(root->val);
    helper(result,root->left,depth,level+1);
    helper(result,root->right,depth,level+1);
}

vector<int> solve(TreeNode* root){
    if(!root){
        return {};
    }
    int depth = GetDepth(root);
    vector<vector<int>> result;
    result.assign(depth,{});
    helper(result,root,depth,0);
    vector<int> ans;
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            ans.push_back(result[i][j]);
        }
    }
    return ans;
}
