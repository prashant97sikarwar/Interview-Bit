//Problem Link:- https://www.interviewbit.com/problems/longest-subarray-length/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    int n = nums.size();
    int count = 0,res = 0;
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        count += (nums[i] == 0 ? -1 : 1);
        if (count == 1){
            res = max(res,i+1);
        }
        if (ump.find(count) == ump.end()){
            ump[count] = i;
        }
        if (ump.find(count-1) != ump.end()){
            res = max(res,i-ump[count-1]);
        }
    }
    return res;
}
