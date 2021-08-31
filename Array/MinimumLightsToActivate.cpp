//Problem Link:- https://www.interviewbit.com/problems/minimum-lights-to-activate/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    int n = nums.size(), i = 0, ans = 0;
    if(k == 0)
        return -1;
    while(i<n){
        int idx = -1;
        //check range [X-B+1, X+B-1] and find rightmost bulb
        for(int j=max(0, i-k+1);j<min(n,i+k);j++){
            if(nums[j] == 1)
                idx = j;
        }
        if(idx == -1)
            return -1;
        ans++;
        //Start now from index which is outside the current selected bulb
        i = idx+k;
    }
    return ans;
}
