//Problem Link:- https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int cur_sum = A[0];
    int max_sum = A[0];
    for(int i=1;i<A.size();i++){
        cur_sum = max(cur_sum+A[i],A[i]);
        max_sum = max(cur_sum,max_sum);
    }
    return max_sum;
}
