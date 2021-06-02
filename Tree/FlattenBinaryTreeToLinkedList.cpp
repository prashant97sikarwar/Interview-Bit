//Problem Link:- https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* flatten(TreeNode* root){
    if (!root){
        return root;
    }
    stack<TreeNode*> pq;
    vector<TreeNode*> nums;
    pq.push(root);
    while (!pq.empty()){
        TreeNode* node = pq.top();
        pq.pop();
        nums.push_back(node);
        if (node->right){
            pq.push(node->right);
        }
        if (node->left){
            pq.push(node->left);
        }
    }
    TreeNode* node = nums[0];
    root = node;
    for(int i=1;i<nums.size();i++){
        node->right = nums[i];
        node->left = NULL;
        node = node->right;
    }
    return root;
}
