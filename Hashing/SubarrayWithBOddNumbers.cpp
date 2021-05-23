//Problem Link:- https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int,int> ump;
    ump[0] = 1;
    vector<int> prefix(n,0);
    if (nums[0] % 2 == 0){
        prefix[0] = 0;
    }
    else{
        prefix[0] = 1;
    }
    for(int i=1;i<n;i++){
        if (nums[i]%2 == 1){
            prefix[i] = prefix[i-1] + 1;
        }
        else{
            prefix[i] = prefix[i-1];
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        if (ump.find(prefix[i] - k) != ump.end()){
            res += ump[prefix[i] - k];
        }
        ump[prefix[i]]++;
    }
    return res;
}
