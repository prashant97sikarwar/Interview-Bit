//Problem Link:- https://www.interviewbit.com/problems/wave-array/

#include<bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i=0;i<n-1;i+=2){
        swap(nums[i],nums[i+1]);
    }
    return nums;
}
