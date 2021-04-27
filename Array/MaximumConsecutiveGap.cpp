//Problem Link:- https://www.interviewbit.com/problems/maximum-consecutive-gap/

#include<bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &nums) {
    vector<int> temp(nums.begin(),nums.end());
    sort(temp.begin(),temp.end());
    int res = INT_MIN;
    int n = nums.size();
    if (n <= 1){
        return 0;
    }
    for(int i=1;i<n;i++){
        res = max(res,temp[i]-temp[i-1]);
    }
    return res;
}
