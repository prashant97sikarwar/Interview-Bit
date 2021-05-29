//Problem Link:- https://www.interviewbit.com/problems/postorder-traversal/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    if (!root){
        return result;
    }
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()){
        TreeNode* node = st.top();
        result.push_back(node->val);
        st.pop();
        if (node->left){
            st.push(node->left);
        }
        if (node->right){
            st.push(node->right);
        }
    }
    reverse(result.begin(),result.end());
    return result;
}