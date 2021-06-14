//Problem Link:- https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &nums){
    int n = nums.size();
    if (n == 0){
        return 0;
    }
    int m = nums[0].size();
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            nums[i][j] += nums[i][j-1];
        }
    }
    int res = 0;
    unordered_map<int,int> mp;
    for(int c1=0;c1<m;c1++){
        for(int c2=c1;c2<m;c2++){
            mp.clear();
            mp[0] = 1;
            int sm = 0;
            for(int row=0;row<n;row++){
                sm += nums[row][c2] - (c1 == 0 ? 0 : nums[row][c1-1]);
                if (mp.count(sm) > 0){
                    res += mp[sm];
                }
                mp[sm]++;
            }
            
        }
    }
    return res;
}
