//Problem Link:- https://www.interviewbit.com/old/problems/unique-binary-search-trees/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> helper(int left,int right){
    vector<TreeNode*> result;
    if (left > right){
        result.push_back(NULL);
        return result;
    }
    for(int i=left;i<=right;i++){
        vector<TreeNode*> leftSide = helper(left,i-1);
        vector<TreeNode*> rightSide = helper(i+1,right);
        for(auto x : leftSide){
            for(auto y : rightSide){
                TreeNode* root = new TreeNode(i);
                root->left = x;
                root->right = y;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> result;
    if (n == 0){
        return result;
    }
    return helper(1,n);
}
