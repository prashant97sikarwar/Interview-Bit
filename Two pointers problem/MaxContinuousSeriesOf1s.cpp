//Problem Link:- https://www.interviewbit.com/problems/max-continuous-series-of-1s/

#include<bits/stdc++.h>
using namespace std;

vector<int> maxone(vector<int> &nums, int k) {
    int left = 0;
    int f = 0;
    int r = 0;
    int n = nums.size();
    int sz = -1;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if (nums[i] == 0){
            cnt++;
        }
        while(cnt > k && left < n){
            if(nums[left] == 0){
                cnt--;
            }
            left++;
        }
        if (i-left+1 > sz){
            f = left;
            r = i;
            sz = i-left+1;
        }
    }
    vector<int> result;
    for(int i=f;i<=r;i++){
        result.push_back(i);
    }
    return result;
    
}
