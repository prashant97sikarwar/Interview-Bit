//Problem Link:- https://www.interviewbit.com/problems/majority-element/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &nums){
    int n = nums.size();
    int ans = INT_MIN;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if (ans == nums[i]){
            cnt++;
        }
        else if (cnt == 0){
            ans = nums[i];
            cnt = 1;
        }
        else{
            cnt--;
        }
    }
    cnt = 0;
    for(int i=0;i<n;i++){
        if (ans == nums[i]){
            cnt++;
        }
    }
    if (cnt > n/2){
        return ans;
    }
    return ans;
}
