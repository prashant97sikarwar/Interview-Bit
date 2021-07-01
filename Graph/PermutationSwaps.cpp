//Problem Link:- https://www.interviewbit.com/old/problems/permutation-swaps/

#include<bits/stdc++.h>
using namespace std;

int find(int a,vector<int>& parent){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a],parent);
}

void merge(int a, int b,vector<int>& parent,vector<int>& rank){
    int x = find(a,parent);
    int y = find(b,parent);
    if (x == y){
        return;
    }
    if (x != y){
        if (rank[x] > rank[y]){
            parent[y] = x;
            rank[x] += rank[y];
        }
        else{
            parent[x] = y;
            rank[y] += rank[x];
        }
    }
}

int solve(vector<int> &nums1, vector<int> &nums2, vector<vector<int> > &arr){
    int n = nums1.size();
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<arr.size();i++){
        int a = nums2[arr[i][0]-1];
        int b = nums2[arr[i][1]-1];
        merge(a,b,parent,rank);
    }
    for(int i=0;i<nums1.size();i++){
        if (nums1[i] != nums2[i]){
            int x = find(nums1[i],parent);
            int y = find(nums2[i],parent);
            if (x != y){
                return 0;
            }
        }
    }
    return 1;
}
