//Problem Link:- https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums,int k){
    int n = nums.size();
    int left = 0;
    unordered_map<int,int> ump;
    int res = 0;
    for(int i=0;i<n;i++){
        ump[nums[i]]++;
        while(ump.size() > k && left < n){
            ump[nums[left]]--;
            if(ump[nums[left]] == 0){
                ump.erase(nums[left]);
            }
            left++;
        }
        res += (i-left+1);
    }
    return res;
}

int solve(vector<int> &nums, int k) {
    return helper(nums,k) - helper(nums,k-1);
}
