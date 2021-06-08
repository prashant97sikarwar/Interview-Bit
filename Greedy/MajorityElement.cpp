//Problem Link:- https://www.interviewbit.com/problems/majority-element/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &nums){
    int n = nums.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
        if (mp[nums[i]] > n/2){
            return nums[i];
        }
    }
    return 0;
}
