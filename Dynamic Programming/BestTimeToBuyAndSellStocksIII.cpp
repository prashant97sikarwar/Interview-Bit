//Problem link:- https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &nums){
    int n = nums.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    int mn = nums[0];
    for(int i=1;i<n;i++){
        if (nums[i] < mn){
            mn = nums[i];
        }
        left[i] = max(nums[i] - mn,left[i-1]);
    }
    int mx = nums[n-1];
    for(int i=n-2;i>=0;i--){
        if (nums[i] > mx){
            mx = nums[i];
        }
        right[i] = max(right[i+1],mx - nums[i]);
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res = max(res,left[i] + right[i]);
    }
    return res;
}
