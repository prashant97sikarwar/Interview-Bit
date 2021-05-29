//Problem Link:- https://www.interviewbit.com/problems/inorder-traversal/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root){
    vector<int> result;
    if (!root){
        return result;
    }
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while (curr != NULL || !st.empty()){
        while (curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        result.push_back(curr->val);
        st.pop();
        curr = curr->right;
    }
    return result;
}
