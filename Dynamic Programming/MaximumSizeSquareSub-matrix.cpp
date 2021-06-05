//Problem Link:- https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums){
    int n = nums.size();
    vector<int> left(n,0), right(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if (st.empty()){
            left[i] = 0;
            st.push(i);
        }
        while (!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        if (st.empty()){
            right[i] = n-1;
            st.push(i);
        }
        while (!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        right[i] = st.empty() ? n-1 : st.top() -1;
        st.push(i);
    }
    int res = -1;
    for(int i=0;i<n;i++){
        int side = min(right[i] - left[i] + 1, nums[i]);
        res = max(res,side*side);
    }
    return res;
}

int solve(vector<vector<int> > &matrix){
    int n = matrix.size();
    if (n == 0){
        return 0;
    }
    int m = matrix[0].size();
    vector<int> nums(m,0);
    int area = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (matrix[i][j] == 0){
                nums[j] = 0;
            }
            else{
                nums[j] += 1;
            }
        }
        area = max(area,helper(nums));
    }
    return area;
}
