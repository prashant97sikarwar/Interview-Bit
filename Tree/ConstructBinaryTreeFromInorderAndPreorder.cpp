//Problem Link:- https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int>&preorder, vector<int>& inorder,int pres, int pree, int ins,int ine, unordered_map<int,int>&mp){
     if (pres > pree || ins > ine){
         return NULL;
     }
     int index = mp[preorder[pres]];
     TreeNode* root = new TreeNode(inorder[index]);
     root->left = helper(preorder,inorder,pres+1,pres+index-ins,ins,index,mp);
     root->right = helper(preorder,inorder,pres+index-ins+1,pree,index+1,ine,mp);
     return root;
     
 }
 
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
    int n = preorder.size();
    if (n == 0){
        return NULL;
    }
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]] = i;
    }
    return helper(preorder,inorder,0,n-1,0,n-1,mp);
}
