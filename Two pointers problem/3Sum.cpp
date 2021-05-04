//Problem Link:- https://www.interviewbit.com/problems/3-sum/


#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int diff = INT_MAX;
    int res = -1;
    for(int i=0;i<n;i++){
        int sm = nums[i];
        int l = i+1;
        int r = n-1;
        while (l < r){
            int tot = sm + nums[l] + nums[r];
            if (abs(tot - k) < diff){
                res = tot;
                diff = abs(tot - k);
            }
            if (tot == k){
                return tot;
            }
            else if (tot > k){
                r--;
            }
            else{
                l++;
            }
        }
    }
    return res;
}
