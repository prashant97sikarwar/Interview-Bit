//Problem Link:- https://www.interviewbit.com/problems/distinct-numbers-in-window/

#include<bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &nums, int k){
    int n = nums.size();
    if (k > n){
        return {};
    }
    vector<int> result;
    int left = 0;
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        ump[nums[i]]++;
        while (left < n && i-left+1 >= k){
            result.push_back(ump.size());
            ump[nums[left]]--;
            if (ump[nums[left]] == 0){
                ump.erase(nums[left]);
            }
            left++;
        }
    }
    return result;
}
