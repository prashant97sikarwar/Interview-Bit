//Problem Link:- https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &nums){
    int n = nums.size();
    int m = nums[0].size();
    int dp[n+1][m+1];
    for(int i=0;i<m;i++){
        dp[0][i] = nums[0][i];
        for(int j=1;j<n;j++){
            dp[j][i] = (nums[j][i] == 0 ? 0 : dp[j-1][i] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        int count[n + 1] = { 0 };
  
        for (int j = 0; j < m; j++)
            count[dp[i][j]]++;
  
        int col_no = 0;
        for (int j = n; j >= 0; j--) {
            if (count[j] > 0) {
                for (int k = 0; k < count[j]; k++) {
                    dp[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
    int curr_area, max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            curr_area = (j + 1) * dp[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}
