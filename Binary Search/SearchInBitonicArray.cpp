//problem Link:- https://www.interviewbit.com/problems/search-in-bitonic-array/

#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>&nums){
    int l = 0;
    int r = nums.size()-1;
    while (l < r){
        int mid = l + (r-l) / 2;
        if (nums[mid] < nums[mid+1]){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return l;
}

int search(vector<int>& nums,int k,int l,int r){
    while (l <= r){
        int mid = l + (r-l)/2;
        if (nums[mid] == k){
            return mid;
        }
        else if (nums[mid] > k){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

int solve(vector<int> &nums, int B) {
    int hgh = peak(nums);
    if (nums[hgh] == B){
        return hgh;
    }
    auto it = lower_bound(nums.begin(),nums.begin()+hgh,B);
    if (it != nums.begin()+hgh && *it == B){
        return it-nums.begin();
    }
    int id = search(nums,B,hgh+1,nums.size()-1);
    return id;
}
