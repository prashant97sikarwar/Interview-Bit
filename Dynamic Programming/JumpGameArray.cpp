//Problem Link:- https://www.interviewbit.com/problems/jump-game-array/

#include<bits/stdc++.h>
using namespace std;

int canJump(vector<int> &nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        nums[i] = i + nums[i];
    }
    int check = n-1;
    for(int i=n-2;i>=0;i--){
        if (nums[i] >= check){
            check = i;
        }
    }
    if (check == 0){
        return 1;
    }
    return 0;
    
}
