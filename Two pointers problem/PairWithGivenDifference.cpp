//Problem Link;- https://www.interviewbit.com/problems/pair-with-given-difference/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    set<int> s;
    for(int i=0;i<nums.size();i++){
        if (s.find(nums[i]-k) != s.end() || s.find(nums[i]+k) != s.end()){
            return 1;
        }
        else{
            s.insert(nums[i]);
        }
    }
    return 0;
}

