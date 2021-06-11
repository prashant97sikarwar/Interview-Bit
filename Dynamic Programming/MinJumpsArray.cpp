//Problem Link:- https://www.interviewbit.com/problems/min-jumps-array/

#include<bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums){
    int n = nums.size();
    if (n == 1){
        return 0;
    }
    int max_reach = nums[0];
    int reach = -1;
    int jumps = 1;
    for(int i=1;i<n;i++){
        if (i > max_reach){
            jumps++;
            max_reach = reach;
            reach = -1;
        }
        if (i <= max_reach && i + nums[i] > reach){
            reach = i + nums[i];
        }
    }
    if(max_reach < nums.size()-1 || max_reach == -1){
        jumps = -1;
    }
    
    return jumps;
}
