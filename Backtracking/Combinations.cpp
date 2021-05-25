//Problem Link:- https://www.interviewbit.com/problems/combinations/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &result,vector<int> temp,int n,int k,int idx){
    if (temp.size() == k){
        sort(temp.begin(),temp.end());
        result.push_back(temp);
        return;
    }
    if (idx > n || temp.size() > k){
        return;
    }
    temp.push_back(idx);
    helper(result,temp,n,k,idx+1);
    temp.pop_back();
    helper(result,temp,n,k,idx+1);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> temp;
    helper(result,temp,n,k,1);
    return result;
}
