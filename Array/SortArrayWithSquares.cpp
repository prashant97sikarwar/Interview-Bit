//Problem Link:- https://www.interviewbit.com/problems/sort-array-with-squares/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums) {
    int n = nums.size();
    int left = 0;
    int right = n-1;
    vector<int> result;
    while (left <= right){
        if (nums[left]*nums[left] <= nums[right]*nums[right]){
            result.push_back(nums[right]*nums[right]);
            right--;
        }
        else{
            result.push_back(nums[left]*nums[left]);
            left++;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
