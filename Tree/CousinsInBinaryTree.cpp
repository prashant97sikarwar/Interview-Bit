//Problem Link:- https://www.interviewbit.com/problems/cousins-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode* root, int k){
    if (!root){
        return {};
    }    
    queue<TreeNode*> pq;
    pq.push(root);
    bool found = false;
    while (!pq.empty()){
        int sz = pq.size();
        vector<int> nums;
        while  (sz--){
            bool flag = false;
            TreeNode* node = pq.front();
            pq.pop();
            if (node->left != NULL && node->left->val == k || node->right != NULL && node->right->val == k){
                flag = true;
                found = true;
            }
            if (node->left){
                if (flag == false){
                    nums.push_back(node->left->val);
                }
                pq.push(node->left);
            }
            if (node->right){
                if (flag == false){
                    nums.push_back(node->right->val);
                }
                pq.push(node->right);
            }
        }
        if (found){
            return nums;
        }
    }
    return {};
}