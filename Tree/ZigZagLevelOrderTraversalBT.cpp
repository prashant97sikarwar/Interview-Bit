//Problem Link:- https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;
    if (!root){
        return result;
    }
    queue<TreeNode*> pq;
    pq.push(root);
    int level = 1;
    while (!pq.empty()){
        int sz = pq.size();
        vector<int> nums;
        while (sz--){
            TreeNode* node = pq.front();
            pq.pop();
            nums.push_back(node->val);
            if (node->left){
                pq.push(node->left);
            }
            if (node->right){
                pq.push(node->right);
            }
        }
        if (level%2 == 0){
            reverse(nums.begin(),nums.end());
        }
        result.push_back(nums);
        level++;
    }
    return result;
}