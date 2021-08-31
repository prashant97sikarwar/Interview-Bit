//Problem Link:- https://www.interviewbit.com/old/problems/convert-sorted-list-to-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
TreeNode* helper(int l,int r,vector<int>&nums){
    if (l <= r){
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(l,mid-1,nums);
        root->right = helper(mid+1,r,nums);
        return root;
    }
    else{
        return NULL;
    }
}


TreeNode* sortedListToBST(ListNode* head) {
    if (!head){
        return NULL;
    }
    if (!head->next){
        TreeNode* temp = new TreeNode(head->val);
        return temp;
    }
    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
    
}
