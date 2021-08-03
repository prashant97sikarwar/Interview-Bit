//Problem Link:- https://www.interviewbit.com/old/problems/black-shapes/

#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int i,int j,int n, int m,vector<string> &nums){
    if (i < 0 || j < 0 || i >= n || j >= m || nums[i][j] != 'X'){
        return;
    }
    nums[i][j] = 'O';
    for(int k=0;k<4;k++){
        int nr = i + dx[k];
        int ny = j + dy[k];
        dfs(nr,ny,n,m,nums);
    }
}

int black(vector<string> &nums){
    const int n = nums.size();
    const int m = nums[0].size();

    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (nums[i][j] == 'X'){
                dfs(i,j,n,m,nums);
                result++;
            }
        }
    }
    return result;
}
