//Problem Link:- https://www.interviewbit.com/problems/maximum-ones-after-modification/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0,sz=-1,cnt=0;
    for(int i=0;i<n;i++){
        if (nums[i] == 0){
            cnt++;
        }
        while(left < n && cnt > k){
            if (nums[left] == 0){
                cnt--;
            }
            left++;
        }
        sz = max(sz,i-left+1);
    }
    return sz;
}
