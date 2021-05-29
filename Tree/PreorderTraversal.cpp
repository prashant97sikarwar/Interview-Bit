//Problem Link:- https://www.interviewbit.com/problems/preorder-traversal/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
vector<int> preorderTraversal(TreeNode* root){
    vector<int> result;
    if (!root){
        return result;
    }
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->right){
            st.push(node->right);   
        }
        if (node->left){
            st.push(node->left);   
        }
    }
    return result;
}
