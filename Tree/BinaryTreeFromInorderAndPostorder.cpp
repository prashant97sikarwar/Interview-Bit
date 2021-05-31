//Problem Link:- https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int ins,int ine,int posts, unordered_map<int,int> &mp){
     if (ins > ine || posts < 0){
         return NULL;
     }
     int index = mp[postorder[posts]];
     TreeNode* root = new TreeNode(postorder[posts]);
     root->left = helper(inorder,postorder,ins,index-1,posts-(ine-index)-1,mp);
     root->right = helper(inorder,postorder,index+1,ine,posts-1,mp);
     return root;
 }
 
TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder){
    int n = postorder.size();
    if (n == 0){
        return NULL;
    }
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]] = i;
    }
    return helper(inorder,postorder,0,n-1,n-1,mp);
}