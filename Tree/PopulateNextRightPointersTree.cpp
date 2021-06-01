//Problem Link:- https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root){
    if (!root){
        return;
    }
    if (!root->left && !root->right){
        root->next = NULL;
        return;
    }
    queue<TreeLinkNode*> pq;
    pq.push(root);
    while(!pq.empty()){
        int sz = pq.size();
        while (sz--){
            TreeLinkNode* node = pq.front();
            pq.pop();
            if (node->left){
                pq.push(node->left);
            }
            if (node->right){
                pq.push(node->right);
            }
            if (sz == 0){
                node->next = NULL;
            }
            if (sz != 0){
                node->next = pq.front();
            }
        }
    }
    return ;
}