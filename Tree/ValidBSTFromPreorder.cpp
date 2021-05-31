//Problem Link:- https://www.interviewbit.com/problems/valid-bst-from-preorder/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(vector<int> &a) {
    stack<int> s;
    int root = INT_MIN;
    
    int n = a.size();
    for(int i =0 ; i<n ;i++){
        
        while(!s.empty()&&a[i]>s.top()){
            root = s.top();
            s.pop();
        }
        
        if(root>a[i])
        return 0;
        
        s.push(a[i]);
        
    }
    return 1;
}
