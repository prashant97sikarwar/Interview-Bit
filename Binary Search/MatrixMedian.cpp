//Problem Link:- https://www.interviewbit.com/problems/matrix-median/

#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &nums) {
    int n = nums.size();
    int m = nums[0].size();
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mn = min(mn,nums[i][0]);
        mx = max(mx,nums[i][m-1]);
    }
    int left = mn;
    int right = mx;
    int threshold = (n*m + 1)/2;
    while (left < right){
        int mid = left + (right-left)/2;
        int place = 0;
        for(int i=0;i<n;i++){
            place += (upper_bound(nums[i].begin(),nums[i].end(),mid) - nums[i].begin());
        }
        if (place < threshold){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return left;
}