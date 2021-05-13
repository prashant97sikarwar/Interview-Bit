//Problem Link:- https://www.interviewbit.com/problems/maximum-path-in-triangle/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &nums) {
    int n = nums.size();
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            nums[i][j] = max(nums[i][j] + nums[i+1][j],nums[i][j] + nums[i+1][j+1]);
        }
    }
    return nums[0][0];
}
