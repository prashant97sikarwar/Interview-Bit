//Problem Link;- https://www.interviewbit.com/courses/programming/topics/binary-search/

#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int B) {
    if (nums[nums.size()-1] < B){
        return nums.size();
    }
    int l = 0;
    int r = nums.size()-1;
    while (l < r){
        int mid = l + (r-l)/2;
        if (nums[mid] >= B){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}
