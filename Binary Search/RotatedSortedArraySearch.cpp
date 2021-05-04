//Problem link;- https://www.interviewbit.com/problems/rotated-sorted-array-search/

#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> nums,int l,int r){
    if (r < l){
        return 0;
    }
    if (r == l){
        return l;
    }
    int mid = l + (r-l)/2;
    if (mid < r && nums[mid] > nums[mid+1]){
        return mid+1;
    }
    if (mid > l && nums[mid] < nums[mid-1]){
        return mid;
    }
    if (nums[mid] > nums[r])
        return findPivot(nums,mid+1,r);
    return findPivot(nums,l,mid-1);
}

int bsearch(vector<int> nums,int l,int r,int k){
    while (l <= r){
        int mid = l + (r-l)/2;
        if (nums[mid] == k){
            return mid;
        }
        else if (nums[mid] > k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }   
    }
    return -1;
}

int search(const vector<int> &nums, int k) {
    int idx = findPivot(nums,0,nums.size()-1);
    if (nums[idx] == k){
        return idx;
    }
    if (nums[idx] > k){
        return -1;
    }
    if (k <= nums[nums.size()-1]){
        return bsearch(nums,idx+1,nums.size()-1,k);
    }
    return bsearch(nums,0,idx-1,k);
}
