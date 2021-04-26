//Problem Link:- https://www.interviewbit.com/problems/noble-integer/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        auto it = upper_bound(nums.begin(),nums.end(),nums[i]);
        if (nums[i] == 0 && it == nums.end()){
            return 1;
        }
        else if (it == nums.end()){
            return -1;
        }
        else if (nums.end()-it == nums[i]){
            return 1;
        }
    }
    return -1;
    
}
