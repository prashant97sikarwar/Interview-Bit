//Problem Link:- https://www.interviewbit.com/problems/first-repeating-element/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    unordered_map<int,int> ump;
    int res = -1;
    int idx = nums.size();
    for(int i=0;i<nums.size();i++){
        if (ump.count(nums[i])){
            if (ump[nums[i]] < idx){
                res = nums[i];
                idx = ump[nums[i]];
                
            }
        }
        ump[nums[i]] = i+1;
    }
    return (idx < nums.size()) ? res : -1;
    
}
