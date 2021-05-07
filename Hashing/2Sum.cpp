//Problem Link:- https://www.interviewbit.com/problems/2-sum/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &nums, int k) {
    unordered_map<int,int> ump;
    int n = nums.size(),l = 0,r = 0;
    vector<int> result;
    for(int i=0;i<n;i++){
        if (ump.find(k - nums[i]) != ump.end()){
            result.push_back(ump[k - nums[i]]+1);
            result.push_back(i+1);
            return result;
        }
        else{
            if (ump.find(nums[i]) != ump.end()){
                continue;
            }
            else{
                ump[nums[i]] = i;
            }
        }
    }
    return result;
}


