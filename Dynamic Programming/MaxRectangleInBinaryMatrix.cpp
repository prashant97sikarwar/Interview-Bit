//Problem Link:- https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums){
    int n = nums.size();
    vector<int> left(n), right(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while (!st.empty() &&  nums[st.top()] >= nums[i]){
            st.pop();
        }
        left[i] = (st.empty() ? 0 : st.top()+1);
        st.push(i);
    }
    while (!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        right[i] = (st.empty() ? n-1 : st.top()-1);
        st.push(i);
    }
    int res = -1;
    for(int i=0;i<n;i++){
        res = max(res, nums[i]*(right[i]-left[i]+1));
    }
    return res;
}

int maximalRectangle(vector<vector<int> > &mat){
    int n = mat.size();
    if (n == 0){
        return 0;
    }
    int m = mat[0].size();
    int res = INT_MIN;
    vector<int> nums(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (mat[i][j] == 0){
                nums[j] = 0;
            }
            else{
                nums[j]++;
            }
        }
        res = max(res,helper(nums));
    }
    return res;
}
