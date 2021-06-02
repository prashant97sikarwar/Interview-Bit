//Problem Link:- https://www.interviewbit.com/problems/burn-a-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findNode(TreeNode *root, int target) {
    if(root == nullptr) {
        return nullptr;
    }

    if(target == root->val) {
        return root;
    }

    TreeNode *left = findNode(root->left, target);
    TreeNode *right = findNode(root->right, target);

    if(left == nullptr && right == nullptr) {
        return nullptr;
    }
    return (left == nullptr) ? right : left;
}

void storeParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode *prev) {
    if(root == nullptr) {
        return;
    }
    parent[root] = prev;
    prev = root;
    storeParent(root->left, parent, prev);
    storeParent(root->right, parent, prev);
}

int minTimeUtil(TreeNode *targetNode, unordered_map<TreeNode*, TreeNode*> &parent, unordered_map<TreeNode*, bool> isVisited) {
    queue<pair<TreeNode*, int>> q;
    q.push({targetNode, 0});
    int maxLevel = 0;

    while(!q.empty()) {
        pair<TreeNode*, int> onTop = q.front();
        q.pop();
        TreeNode *curNode = onTop.first;
        int curLevel = onTop.second;
        if(curLevel > maxLevel) {
            maxLevel = curLevel;
        }

        if(isVisited[curNode] == false) {
            isVisited[curNode] = true;

            if(curNode->left && !isVisited[curNode->left]) {
                q.push({curNode->left, curLevel+1});
            }
            if(curNode->right && !isVisited[curNode->right]) {
                q.push({curNode->right, curLevel+1});
            }
            if(parent[curNode] && !isVisited[parent[curNode]]) {
                q.push({parent[curNode], curLevel+1});
            }
        }
    }
    return maxLevel;
}

int solve(TreeNode* root, int target) {

    TreeNode *targetNode = findNode(root, target);
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode *prev = nullptr;
    storeParent(root, parent, prev);

    unordered_map<TreeNode*, bool> isVisited;
    return minTimeUtil(targetNode, parent, isVisited);
}

