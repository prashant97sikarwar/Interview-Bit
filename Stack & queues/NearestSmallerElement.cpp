//Problem Link:- https://www.interviewbit.com/problems/nearest-smaller-element/

#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result;
    for(int i=0;i<n;i++){
        while (!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        if (st.empty()){
            result.push_back(-1);
        }
        else{
            result.push_back(st.top());
        }
        st.push(nums[i]);
    }
    return result;
}
