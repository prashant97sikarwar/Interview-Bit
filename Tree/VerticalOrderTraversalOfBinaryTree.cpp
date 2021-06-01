//Problem Link:- https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrderTraversal(TreeNode* A) {

    vector<vector<int>> ans;
    map<int,vector<int>> mp;
    if ( A==NULL ) return ans;
    queue < pair<TreeNode*, int> > q;
    q.push( {A,0} );
    TreeNode *tmp;
    int hrz;
    while ( !q.empty() ){
        int rnfr = q.size();
        for ( int i=0; i<rnfr; i++ ){
            tmp = q.front().first;
            hrz = q.front().second;
            mp[hrz].push_back(tmp->val);
            q.pop();
            if ( tmp->left != NULL ) q.push( {tmp->left,hrz-1} );
            if ( tmp->right != NULL ) q.push( {tmp->right,hrz+1} );
        }
    }

    for ( auto it: mp ){
        ans.push_back(it.second);
    }
    return ans;    
}