//Problem Link:- https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(const vector<int>& nums,int left, int right){
     if (left > right){
         return NULL;
     }
     int mid = left + (right - left)/2;
     TreeNode* root = new TreeNode(nums[mid]);
     root->left = helper(nums,left,mid-1);
     root->right = helper(nums,mid+1,right);
     return root;
 }
 
TreeNode* sortedArrayToBST(const vector<int> &nums){
    int n = nums.size();
    if (n == 0){
        return NULL;
    }
    if (n == 1){
        TreeNode* temp = new TreeNode(nums[0]);
        return temp;
    }
    return helper(nums,0,n-1);
}
