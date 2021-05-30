//Problem Link:- https://www.interviewbit.com/problems/path-to-given-node/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, int k,vector<int>& result){
    if (!root){
        return false;
    }
    result.push_back(root->val);
    if (root->val == k){
        return true;
    }
    if (helper(root->left,k,result) || helper(root->right,k,result)){
        return true;
    }
    result.pop_back();
    return false;
}
 
vector<int> solve(TreeNode* root, int k){
    vector<int> result;
    bool flag = helper(root,k,result);
    return result;
}
