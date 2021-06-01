//Problem Link:- https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findIndex(vector<int>& nums,int left, int right){
    int res = INT_MIN;
    int idx = -1;
    for(int i=left;i<=right;i++){
        if (nums[i] > res){
            res = nums[i];
            idx = i;
        }
    }
    return idx;
} 

TreeNode* helper(vector<int>& nums,int left, int right){
    if (left > right){
        return NULL;
    }
    int idx = findIndex(nums,left,right);
    TreeNode* root = new TreeNode(nums[idx]);
    if (left == right){
        return root;
    }
    root->left = helper(nums,left,idx-1);
    root->right = helper(nums,idx+1,right);
    return root;
} 

TreeNode* buildTree(vector<int> &nums){
    int n = nums.size();
    if (n == 0){
        return NULL;
    }
    return helper(nums,0,n-1);
}
