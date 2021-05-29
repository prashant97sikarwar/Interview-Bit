//Problem Link:- https://www.interviewbit.com/problems/identical-binary-trees/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int isSameTree(TreeNode* p, TreeNode* q){
    if (p == NULL && q == NULL){
        return true;
    }
    if (p == NULL || q == NULL){
        return false;
    }
    if (p->val != q->val){
        return false;
    }
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
