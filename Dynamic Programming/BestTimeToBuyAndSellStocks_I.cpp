//Problem Link:- https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &nums) {
    int res = 0,n = nums.size();
    if (n == 0 || n == 1){
        return 0;
    }
    int mn = nums[0];
    for(int i=1;i<n;i++){
        if (nums[i] >= mn){
            res = max(res,nums[i]-mn);
        }
        else{
            mn = nums[i];
        }
    }
    return res;
}
