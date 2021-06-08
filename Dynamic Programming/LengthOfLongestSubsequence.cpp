//Problem Link:- https://www.interviewbit.com/problems/length-of-longest-subsequence/

#include<bits/stdc++.h>
using namespace std;

int longestSubsequenceLength(const vector<int> &nums){
    int n = nums.size();
    if (n == 0 || n == 1){
        return n;
    }
    vector<int> left(n,1), right(n,1);
    vector<int> seq;
    seq.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if (nums[i] > seq.back()){
            seq.push_back(nums[i]);
        }
        else{
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            int idx = it - seq.begin();
            seq[idx] = nums[i];
        }
        left[i] = seq.size();
    }
    seq.clear();
    seq.push_back(nums[n-1]);
    for(int i=n-2;i>=0;i--){
        if (nums[i] > seq.back()){
            seq.push_back(nums[i]);
        }
        else{
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            int idx = it - seq.begin();
            seq[idx] = nums[i];
        }
        right[i] = seq.size();
    }
    int res = 1;
    for(int i=0;i<n;i++){
        res = max(res,left[i] + right[i] - 1);
    }
    return res;
}
