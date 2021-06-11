//Problem Link:- https://www.interviewbit.com/problems/egg-drop-problem/

#include<bits/stdc++.h>
using namespace std;

int attempts(int eggs, int floors, int dp[][10005]) {
        if (floors == 0 or floors == 1) {
            return dp[eggs][floors] = floors;
        }
        if (eggs == 0) {
            return dp[eggs][floors] = 0;
        }
        if (eggs == 1) {
            return dp[eggs][floors] = floors;
        }
         if (dp[eggs][floors] != -1) {
            return dp[eggs][floors];
        }
        int left, right;
        int low = 1, high = floors, ans = INT_MAX;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (dp[eggs-1][mid-1] != -1){
                left = dp[eggs-1][mid-1];
            }
            else {
                left = attempts(eggs-1, mid-1, dp);
            }
            
            if (dp[eggs][floors-mid] != -1) {
                right = dp[eggs][floors-mid];
            }
            else {
                right = attempts(eggs, floors-mid, dp);
            }
            
            ans = min(ans, 1+ max(left, right));
            
            if (left > right) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        dp[eggs][floors] = ans;
        return dp[eggs][floors];
    }

int solve(int eggs, int floors){
    int dp[101][10005];
    memset(dp, -1, sizeof(dp));
    return attempts(eggs, floors, dp);
}
