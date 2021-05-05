//Problem Link:- https://www.interviewbit.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &nums) {
    int res = 0;
    int l = 0;
    int r = nums.size()-1;
    while (l < r){
        int area = min(nums[l],nums[r])*(r-l);
        res = max(res,area);
        if (nums[l] < nums[r]){
            l++;
        }
        else{
            r--;
        }
    }
    return res;
}
