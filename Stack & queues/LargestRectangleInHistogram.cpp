//Problem Link:- https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    vector<int> left(n), right(n);
    for(int i=0;i<n;i++){
        if (st.empty()){
            left[i] = 0;
            st.push(i);
        }
        else{
            while (!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
    }
    while (!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        if (st.empty()){
            right[i] = n-1;
            st.push(i);
        }
        else{
            while (!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            right[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res = max(res,(right[i] - left[i] + 1)*nums[i]);
    }
    return res;
}
