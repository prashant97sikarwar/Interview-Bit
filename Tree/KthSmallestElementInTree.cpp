//Problem link:- https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root,vector<int>& result){
    if (!root){
        return;
    }
    helper(root->left, result);
    result.push_back(root->val);
    helper(root->right,result);
}
 
int kthsmallest(TreeNode* root, int k){
    vector<int> result;
    helper(root,result);
    return result[k-1];
}