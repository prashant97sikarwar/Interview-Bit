//Problem Link:- https://www.interviewbit.com/problems/unique-paths-in-a-grid/

#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &grid){
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n, vector<int> (m,0));
    if (grid[n-1][m-1] == 1){
        return 0;
    }
    dp[n-1][m-1] = 1;
    for(int i=m-2;i>=0;i--){
        if (grid[n-1][i] == 0){
            dp[n-1][i] += dp[n-1][i+1];
        }
        else{
            dp[n-1][i] = 0;
        }
    }
    for(int i=n-2;i>=0;i--){
        if (grid[i][m-1] == 0){
            dp[i][m-1] += dp[i+1][m-1];
        }
        else{
            dp[i][m-1] = 0;
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if (grid[i][j] == 0){
                long long k = (long long)dp[i+1][j] + dp[i][j+1];
                if (k >= INT_MAX){
                    k %= 1000000007;
                    dp[i][j] = k;
                }
                else{
                    dp[i][j] = k;   
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}
