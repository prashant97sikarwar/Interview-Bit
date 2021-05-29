//Problem Link:- https://www.interviewbit.com/problems/invert-the-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* invertTree(TreeNode* root){
    if (root == NULL){
        return NULL;
    }
    queue<TreeNode*> pq;
    pq.push(root);
    while (!pq.empty()){
        TreeNode* curr = pq.front();
        pq.pop();
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        if (curr->left != NULL){
            pq.push(curr->left);
        }
        if (curr->right != NULL){
            pq.push(curr->right);
        }
    }
    return root;
}