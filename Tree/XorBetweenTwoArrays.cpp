//Problem Link:- https://www.interviewbit.com/problems/xor-between-two-arrays/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    
    Node(){
        left = NULL;
        right = NULL;
    }
};

void insert(Node* root,int n){
    Node* cur = root;
    for(int i=31;i>=0;i--){
        int bit = (1 << i) & n;
        if (bit == 0){
            if (!cur->left){
                cur->left = new Node();
            }
            cur = cur->left;
        }
        else{
            if (!cur->right){
                cur->right = new Node();
            }
            cur = cur->right;
        }
    }
}

int findXor(Node* root, vector<int>& nums){
    int res = INT_MIN;
    for(int i=0;i<nums.size();i++){
        int value = nums[i];
        int cur_mx = 0;
        Node* cur = root;
        for(int j=31;j>=0;j--){
            int bit = (1 << j) & value;
            if (bit == 0){
                if (cur->right){
                    cur_mx += pow(2,j);
                    cur = cur->right;
                }
                else{
                    cur = cur->left;
                }
            }
            else{
                if (cur->left){
                    cur_mx += pow(2,j);
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                }
            }
        }
        if (cur_mx > res){
            res = cur_mx;
        }
    }
    return res;
}

int solve(vector<int> &nums1, vector<int> &nums2){
    Node* root = new Node();
    for(int i=0;i<nums1.size();i++){
        insert(root,nums1[i]);
    }
    return findXor(root,nums2);
}
