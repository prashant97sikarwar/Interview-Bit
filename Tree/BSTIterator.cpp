//Problem Link:- https://www.interviewbit.com/problems/bst-iterator/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> result;
    void helper(TreeNode* root, vector<int>& result){
        if (!root){
            return;
        }
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while  (curr != NULL || !st.empty()){
            while (curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
    }
int idx = 0;

bool hasNext() {
    if (result.size() > 0){
        return true;
    }
    return false;
}

int next() {
    int res = result[idx];
    result.erase(result.begin());
    return res;
}